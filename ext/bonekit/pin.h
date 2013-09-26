/*
 
 pin.h
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

#ifndef BONEKIT_PIN_H__
#define BONEKIT_PIN_H__

#ifdef __cplusplus
extern "C" {
#endif

struct pin_s
{
  unsigned int _id;

  int _is_ain;
  unsigned _ain;
  int _is_gpio;
  unsigned _gpio;
  int _can_pwm;
  char * _pwm_key;
};

typedef struct pin_s pin_t;

pin_t * pin_alloc();
int pin_init(pin_t *, unsigned int);
void pin_destroy(pin_t *);
int pin_mode(pin_t *);
void pin_set_mode(pin_t *, int);
int pin_value(pin_t *);
double pin_analog_value(pin_t *);
void pin_set_value(pin_t *, int);
void pin_set_analog_value(pin_t *, double);

#ifdef __cplusplus
}
#endif

#endif