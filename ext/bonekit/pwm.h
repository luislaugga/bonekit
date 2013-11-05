/*
 
 pwm.h
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

#ifndef __BONEKIT_PWM_H__
#define __BONEKIT_PWM_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#define OCP_DIR "/sys/devices/ocp.2"
#define SLOTS "/sys/devices/bone_capemgr.8/slots"

#define PWM_LEN 64
  
#define PWM_PERIOD_NS 500000 // nanoseconds
#define PWM_POLARITY 0 // ...

int pwm_enable();
int pwm_enable_pin(const char *);

int pwm_get_key(const char *, char **);

int pwm_export(const char *, char **);
int pwm_unexport(char *);

int pwm_read(char *, const char * , char *, unsigned int);
int pwm_write(char *, const char *, char *);

int pwm_set_polarity(char *, int);
int pwm_get_polarity(char *, int *);

int pwm_set_period(char *, unsigned long);
int pwm_get_period(char *, unsigned long *);

int pwm_set_duty_cycle(char *, double);
int pwm_get_duty_cycle(char *, double *);

#ifdef __cplusplus
}
#endif

#endif
