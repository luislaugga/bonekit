/*
 
 pin.c
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

#include "pin.h"

#include "gpio.h"
#include "adc.h"

#include <stdlib.h>

pin_t * pin_alloc()
{
  pin_t * obj;
  obj = malloc(sizeof(struct pin_s));  
  return obj;
}

int pin_init(pin_t * obj, unsigned int beaglebone_global_const)
{
  if(obj)
  {
    int gpio = beaglebone_gpio(beaglebone_global_const);
    int ain = beaglebone_ain(beaglebone_global_const);
    
    if(!(gpio > 0 || ain > 0)) // invalid pin
      return -1;
    
    obj->_ain = ain;
    obj->_gpio = gpio;
    
    if(gpio)
      gpio_export(gpio);
  }
  
  return 0;
}

void pin_destroy(pin_t * obj)
{
  if(obj->_gpio)
    gpio_unexport(obj->_gpio);
  
  free(obj);
}

int pin_mode(pin_t * obj)
{
  int mode = -1;
  if(obj->_gpio)
    gpio_get_direction(obj->_gpio, &mode);
  return mode;
}

void pin_set_mode(pin_t * obj, int mode)
{
  if(obj->_gpio)
    gpio_set_direction(obj->_gpio, mode);
}

int pin_value(pin_t * obj)
{
  int value = 0;
  
  if(obj->_gpio)
  {
    gpio_get_value(obj->_gpio, &value);
  }
  else if(obj->_ain)
  {
    float analog_value;
    adc_get_value(obj->_ain, &analog_value);
    value = (int)analog_value;
  }
  
  return value;
}

float pin_analog_value(pin_t * obj)
{
  float analog_value = 0.0;
  
  if(obj->_gpio)
  {
    int value;
    gpio_get_value(obj->_gpio, &value);
    analog_value = (float)value;
  }
  else if(obj->_ain)
  {
    adc_get_value(obj->_ain, &analog_value);
  }
  
  return analog_value;
}

void pin_set_value(pin_t * obj, int value)
{
  if(obj->_gpio)
    gpio_set_value(obj->_gpio, value);
}
