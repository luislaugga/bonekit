/*

 gpio.c
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

#include "gpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int gpio_read(unsigned int gpio, const char * filename, char * value, unsigned int length)
{
  int fd, len;
  char filepath[GPIO_LEN];
  snprintf(filepath, sizeof(filepath), "%s/gpio%d/%s", GPIO_DIR, gpio, filename);
  
  if((fd = open(filepath, O_RDONLY | O_NONBLOCK)) < 0)
    return -1;
  
  lseek(fd, 0, SEEK_SET);
  read(fd, value, length);
  close(fd);
  
  return 0;
}

int gpio_write(unsigned int gpio, const char * filename, char * value)
{
  int fd;
  char filepath[GPIO_LEN];
  snprintf(filepath, sizeof(filepath), "%s/gpio%d/%s", GPIO_DIR, gpio, filename);

  if((fd = open(filepath, O_WRONLY)) < 0)
    return -1;

  write(fd, value, strlen(value));
  close(fd);

  return 0;
}

int gpio_export(unsigned int gpio)
{
  int fd, len;
  char str_gpio[10];
    
  if((fd = open("/sys/class/gpio/export", O_WRONLY)) < 0)
    return -1;
    
  len = snprintf(str_gpio, sizeof(str_gpio), "%d", gpio);
  write(fd, str_gpio, len);
  close(fd);
}

int gpio_unexport(unsigned int gpio)
{
  int fd, len;
  char str_gpio[10];
    
  if((fd = open("/sys/class/gpio/unexport", O_WRONLY)) < 0)
    return -1;
    
  len = snprintf(str_gpio, sizeof(str_gpio), "%d", gpio);
  write(fd, str_gpio, len);
  close(fd); 
}

int gpio_set_direction(unsigned int gpio, unsigned int direction)
{
  if(direction == OUTPUT)
  {
    if(gpio_write(gpio, "direction", "out") < 0)
      return -1;   
  }
  else
  {
    if(gpio_write(gpio, "direction", "in") < 0)
      return -1;  
  }
    
  return 0;
}

int gpio_get_direction(unsigned int gpio, unsigned int * direction)
{
  const unsigned int length = 3;
  char buffer[length];
    
  if(gpio_read(gpio, "direction", buffer, length) < 0)
    return -1;
    
  if(strcmp(buffer, "out") == 0)
    *direction = OUTPUT;
  else
    *direction = INPUT;
    
  return 0; 
}

int gpio_set_value(unsigned int gpio, unsigned int value)
{     
  char buffer[GPIO_LEN];
  sprintf(buffer, "%d", value); // convert value to string, decimal base
  
  if(gpio_write(gpio, "value", buffer) < 0)
    return -1;
    
  return 0;
}

int gpio_get_value(unsigned int gpio, unsigned int * value)
{
  const unsigned int length = 2;
  char buffer[length];
    
  if(gpio_read(gpio, "value", buffer, length) < 0)
    return -1;
    
  *value = atoi(buffer);
    
  return 0;
}
