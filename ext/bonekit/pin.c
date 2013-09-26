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

#include "beaglebone.h"
#include "gpio.h"
#include "adc.h"
#include "pwm.h"

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
    int pwm_mux_mode = beaglebone_pwm_mux_mode(beaglebone_global_const);
    
    int is_ain = (ain != -1);
    int is_gpio = (gpio != -1);
    int can_pwm = (pwm_mux_mode != -1);
    
    if(!(is_ain || is_gpio)) // invalid pin
      return -1;
    
    obj->_id = beaglebone_global_const;
    
    obj->_ain = ain;
    obj->_is_ain = is_ain;
    obj->_gpio = gpio;
    obj->_is_gpio = is_gpio;
    
    obj->_can_pwm = can_pwm; 
    obj->_pwm_key = NULL; // lazy pwm export (first call to set_analog_value)
    
    if(is_gpio)
      gpio_export(gpio);
    else if(is_ain)
      adc_enable();
  }
  
  return 0;
}

void pin_destroy(pin_t * obj)
{
  if(obj->_is_gpio)
    gpio_unexport(obj->_gpio);
  
  if(obj->_pwm_key != NULL)
    pwm_unexport(obj->_pwm_key);
  
  free(obj);
}

int pin_mode(pin_t * obj)
{
  int mode = -1;
  if(obj->_is_gpio)
    gpio_get_direction(obj->_gpio, &mode);
  return mode;
}

void pin_set_mode(pin_t * obj, int mode)
{
  if(obj->_is_gpio)
    gpio_set_direction(obj->_gpio, mode);
}

int pin_value(pin_t * obj)
{
  int value = 0;
  
  if(obj->_is_gpio)
  {
    gpio_get_value(obj->_gpio, &value);
  }
  else if(obj->_is_ain)
  {
    int analog_value_raw; // [ADC_MIN_VALUE..ADC_MAX_VALUE]
    adc_get_value(obj->_ain, &analog_value_raw);
    value = analog_value_raw > ADC_THRESHOLD ? HIGH : LOW;
  }
  
  return value;
}

double pin_analog_value(pin_t * obj)
{
  double analog_value = 0.0;
  
  if(obj->_is_gpio)
  {
    int value;
    gpio_get_value(obj->_gpio, &value);
    analog_value = (double)value;
  }
  else if(obj->_is_ain)
  {
    int analog_value_raw; // [ADC_MIN_VALUE..ADC_MAX_VALUE]
    adc_get_value(obj->_ain, &analog_value_raw);
    analog_value = (double)(((double)analog_value_raw)/((double)ADC_MAX_VALUE));
  }
  else if(obj->_pwm_key != NULL)
  {
    pwm_get_duty_cycle(obj->_pwm_key, &analog_value);
  }
    
  return analog_value;
}

void pin_set_value(pin_t * obj, int value)
{
  if(obj->_is_gpio)
    gpio_set_value(obj->_gpio, value);
}

void pin_set_analog_value(pin_t * obj, double value)
{
  if(obj->_can_pwm)
  {
    if(obj->_pwm_key == NULL)
    {
      char pin_name[5];
      beaglebone_pin_name(obj->_id, (char **)(&pin_name)); // retrieve pin name ie. P9_42
      pwm_export(pin_name, &obj->_pwm_key); // retrieve pin pwm key
    }
    
    pwm_set_duty_cycle(obj->_pwm_key, value);
  }
}