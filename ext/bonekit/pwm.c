/*
 
 pwm.c
 BoneKit
 
 Copyright (cc) 2012 Luis Laugga.
 Some rights reserved, all wrongs deserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
*/

#include "pwm.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int pwm_enable()
{
  int fd;
  if((fd = open(SLOTS, O_WRONLY)) < 0)
    return -1;

  const char * am33xx_pwm = "am33xx_pwm";
  write(fd, am33xx_pwm, strlen(am33xx_pwm));
  close(fd);

  return 0;
}

int pwm_enable_pin(const char * pin)
{
  if(pwm_enable() < 0) // enable pwm
    return -1;
  
  int fd;
  if((fd = open(SLOTS, O_WRONLY)) < 0)
    return -1;

  char bone_pwm_pin[15];
  snprintf(bone_pwm_pin, 15, "bone_pwm_%s", pin);
  write(fd, bone_pwm_pin, strlen(bone_pwm_pin)); // enable pwm pin
  close(fd);
  
  return 0;
}

int pwm_get_key(const char * pin, char ** pwm_key)
{
    DIR * dd;
    struct dirent * df;

    dd = opendir(OCP_DIR);
    if(dd != NULL) 
    {
      while((df = readdir(dd))) 
      {
        if(strstr(df->d_name, pin)) 
        {
          int pwm_key_len = strlen(df->d_name)+1;
          *pwm_key = (char *)calloc(pwm_key_len, sizeof(char));
          snprintf(*pwm_key, pwm_key_len, "%s", df->d_name);
          closedir(dd);
          return 0;
        }
      }
      closedir (dd);
    } 
    
    return -1;
}

int pwm_export(const char * pin, char ** pwm_key)
{
  if(pwm_enable_pin(pin) < 0) // enable pin
    return -1;
  
  if(pwm_get_key(pin, pwm_key) < 0) // get key for pin
    return -1;
  
  // Set default values
  pwm_set_polarity(*pwm_key, PWM_POLARITY);
  pwm_set_period(*pwm_key, PWM_PERIOD_NS);

  return 0;
}

int pwm_unexport(char * pwm_key)
{
  if(pwm_key == NULL)
    return -1;
  
  // TODO disable pwm for key
  free(pwm_key);
  
  return 0;
}

int pwm_read(char * pwm_key, const char * filename, char * value, unsigned int length)
{
  if(pwm_key == NULL)
    return -1;
  
  int fd, len;
  char filepath[PWM_LEN];
  snprintf(filepath, sizeof(filepath), "%s/%s/%s", OCP_DIR, pwm_key, filename);
  
  if((fd = open(filepath, O_RDONLY | O_NONBLOCK)) < 0)
    return -1;
  
  lseek(fd, 0, SEEK_SET);
  
  read(fd, value, length);
  sscanf(value, "%s\n", value);
  close(fd);
  
  return 0;
}

int pwm_write(char * pwm_key, const char * filename, char * value)
{
  if(pwm_key == NULL)
    return -1;
  
  int fd;
  char filepath[PWM_LEN];
  snprintf(filepath, sizeof(filepath), "%s/%s/%s", OCP_DIR, pwm_key, filename);

  if((fd = open(filepath, O_WRONLY)) < 0)
    return -1;

  write(fd, value, strlen(value));
  close(fd);

  return 0;
}

int pwm_set_polarity(char * pwm_key, int polarity)
{
  if(pwm_key == NULL)
    return -1;
  
  char value[PWM_LEN];
  snprintf(value, PWM_LEN, "%d", polarity);
  pwm_write(pwm_key, "polarity", value);
  
  return 0;
}

int pwm_get_polarity(char * pwm_key, int * polarity)
{
  if(pwm_key == NULL)
    return -1;
  
  char value[PWM_LEN];
  pwm_read(pwm_key, "polarity", value, PWM_LEN);
  sscanf(value, "%d", polarity);
  
  return 0;
}

int pwm_set_period(char * pwm_key, unsigned long period)
{
  if(pwm_key == NULL)
    return -1;
  
  char value[PWM_LEN];
  snprintf(value, PWM_LEN, "%lu", period);
  pwm_write(pwm_key, "period", value);
}

int pwm_get_period(char * pwm_key, unsigned long * period)
{
  if(pwm_key == NULL)
    return -1;
  
  char value[PWM_LEN];
  pwm_read(pwm_key, "period", value, PWM_LEN);
  sscanf(value, "%lu", period);
  
  return 0;
}

int pwm_set_duty_cycle(char * pwm_key, double duty_cycle) // duty_cycle interval [0.0..1.0]
{
  if(pwm_key == NULL)
    return -1;
  
  if(duty_cycle < 0.0) // Check duty cycle upper bound
    duty_cycle = 0.0;

  if(duty_cycle > 1.0) // Check duty cycle lower bound
    duty_cycle = 1.0;
  
  char value[PWM_LEN];
  snprintf(value, PWM_LEN, "%lu", (unsigned long)(duty_cycle * PWM_PERIOD_NS));
  pwm_write(pwm_key, "duty", value);

  return 0;
}

int pwm_get_duty_cycle(char * pwm_key, double * duty_cycle)
{
  if(pwm_key == NULL)
    return -1;
  
  char value[PWM_LEN];
  pwm_read(pwm_key, "duty", value, PWM_LEN);
  unsigned long duty_cycle_ns = 0.0;
  sscanf(value, "%lu", &duty_cycle_ns);
  
  *duty_cycle = (double)(duty_cycle_ns/((double)PWM_PERIOD_NS));
  
  return 0;
}