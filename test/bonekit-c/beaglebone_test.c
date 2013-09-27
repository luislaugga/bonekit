#include "../../ext/bonekit/beaglebone.h"

#include <stdio.h>

int main()
{
  beaglebone_t p = P9_42;
  
  printf("p %s %x\n", p.pin_name, p.pin_mask);
  
  char pin_name[PIN_NAME_LEN];
  int gpio, ain, pwm_mux_mode;
  
  beaglebone_pin_name(P9_42, pin_name);
  gpio = beaglebone_gpio(P9_42);
  ain = beaglebone_ain(P9_42);
  pwm_mux_mode = beaglebone_pwm_mux_mode(P9_42);
  
  printf("%s %d %d %d\n", pin_name, gpio, ain, pwm_mux_mode);
  
  beaglebone_t u = USR1;
  
  printf("u %s %x\n", u.pin_name, u.pin_mask);
  
  return 0;
}