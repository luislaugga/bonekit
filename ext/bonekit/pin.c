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

#include <stdlib.h>

pin_t * pin_alloc()
{
  pin_t * obj;
  obj = malloc(sizeof(struct pin_s));  
  return obj;
}

void pin_init(pin_t * obj, unsigned int gpio)
{
  if(obj)
  {
    obj->_gpio = gpio;
    gpio_export(gpio);
  }
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
