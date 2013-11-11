/*
 
 adxl345.h
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

#ifndef __BONEKIT_ADXL345_H__
#define __BONEKIT_ADXL345_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#include "i2c.h"

typedef struct
{
	float x;
	float y;
	float z;
} adxl345_vec3_scaled_t;

typedef struct
{
	int x;
	int y;
	int z;
} adxl345_vec3_raw_t;

struct adxl345_s
{
  adxl345_vec3_raw_t _raw_acceleration;
  i2c_t * _i2c;
};

typedef struct adxl345_s adxl345_t;

adxl345_t * adxl345_create();
void adxl345_destroy(adxl345_t *);
adxl345_vec3_raw_t * adxl345_raw_acceleration(adxl345_t * obj);

#ifdef __cplusplus
}
#endif

#endif