/*
 
pin.c
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

#include "pin.h"
#include "gpio.h"

#include <stdlib.h>

pin_t * pin_create(unsigned int gpio)
{
  pin_t * obj;
  obj = malloc(sizeof(struct pin_s));
  if(obj)
  {
    obj->_gpio = gpio;
    gpio_export(gpio);
  }
  
  return obj;
}

void pin_destroy(pin_t * obj)
{
  gpio_unexport(obj->_gpio);
  free(obj);
}

int pin_mode(pin_t * obj)
{
  int mode = -1;
  gpio_get_direction(obj->_gpio, &mode);
  return mode;
}

void pin_set_mode(pin_t * obj, int mode)
{
  gpio_set_direction(obj->_gpio, mode);
}

int pin_value(pin_t * obj)
{
  int value;
  gpio_get_value(obj->_gpio, &value);
  return value;
}

void pin_set_value(pin_t * obj, int value)
{
  gpio_set_value(obj->_gpio, value);
}
