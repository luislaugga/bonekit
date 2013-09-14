/*
*/

#ifndef BONEKIT_GPIO_H__
#define BONEKIT_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#define INPUT  0
#define OUTPUT 1

#define HIGH 1
#define LOW  0
  
int open_value_file(unsigned int);
int gpio_export(unsigned int);
int gpio_set_direction(unsigned int, unsigned int);
int gpio_set_value(unsigned int, unsigned int);
int gpio_get_value(unsigned int, unsigned int*);

#ifdef __cplusplus
}
#endif

#endif