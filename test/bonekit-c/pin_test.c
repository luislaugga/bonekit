#include "../../ext/bonekit/pin.h"

#include <stdio.h>

int main()
{
  beaglebone_t p = P9_42;
  
  pin_t * pin = pin_alloc();
  pin_init(pin, P9_42);
  
  pin_set_analog_value(pin, 1.0);
  
  sleep(1);
  
  pin_set_analog_value(pin, 0.5);
  
  sleep(1);
  
  pin_set_analog_value(pin, 0.0);
  
  pin_destroy(pin);
  
  pin = pin_alloc();
  pin_init(pin, P9_13);
  
  pin_set_mode(pin, OUTPUT);
  pin_set_value(pin, HIGH);
  
  sleep(1);
  
  pin_set_value(pin, LOW);
  
  sleep(1);
  
  pin_set_value(pin, HIGH);
  
  sleep(1);
  
  pin_destroy(pin);
  
  pin = pin_alloc();
  pin_init(pin, P9_39);
  
  printf("analog value %f\n", pin_analog_value(pin));
  
  sleep(1);
  
  printf("analog value %f\n", pin_analog_value(pin));
  
  sleep(1);
  
  pin_destroy(pin);
  
  return 0;
}