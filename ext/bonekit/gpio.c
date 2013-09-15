/*
 
gpio.c
BoneKit
 
Copyright (cc) 2012 Luis Laugga.
Some rights reserved, all wrongs deserved.
 
Licensed under a Creative Commons Attribution-ShareAlike 3.0 License;
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
 
http://creativecommons.org/licenses/by-sa/3.0/
 
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 
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
