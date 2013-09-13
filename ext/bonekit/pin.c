/*
*/

#include "pin.h"

#include <linux/gpio.h>

pin_t * pin_create(unsigned gpio)
{
  pin_t * obj;
  obj = malloc(sizeof(struct pin_s));
  if(obj)
  {
    obj->_gpio = gpio;
    
    obj->_mode = 0;
    gpio_direction_input(gpio);
  }
  
  return obj;
}

void pin_destroy(pin_t * obj)
{
  free(obj);
}

uint8_t pin_mode(pin_t * obj)
{
  return obj->_mode;
}

void pin_set_mode(pin_t * obj, uint8_t mode)
{
  // ...
}

int pin_value(pin_t * obj)
{
	obj->_value = gpio_get_value(obj->_gpio);
  return obj->value;
}

void pin_set_value(pin_t * obj, int value)
{
  obj->_value = value;
  gpio_set_value(obj->_gpio, obj->_value);
}
