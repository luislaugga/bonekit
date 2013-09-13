/*
*/

#include "pin.h"
#include "gpio.h"

#include <stdlib.h>

pin_t * pin_create(unsigned gpio)
{
  pin_t * obj;
  obj = malloc(sizeof(struct pin_s));
  if(obj)
  {
    obj->_gpio = gpio;
  }
  
  return obj;
}

void pin_destroy(pin_t * obj)
{
  free(obj);
}

int pin_mode(pin_t * obj)
{
  return obj->_mode;
}

void pin_set_mode(pin_t * obj, int mode)
{
  obj->_mode = mode;
  gpio_set_direction(obj->_gpio, mode);
}

int pin_value(pin_t * obj)
{
	gpio_get_value(obj->_gpio, &(obj->_value));
  return obj->_value;
}

void pin_set_value(pin_t * obj, int value)
{
  obj->_value = value;
  gpio_set_value(obj->_gpio, obj->_value);
}
