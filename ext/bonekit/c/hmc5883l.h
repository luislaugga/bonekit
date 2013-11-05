/*
 
 hmc5883l.h
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

#ifndef __BONEKIT_HMC5883L_H__
#define __BONEKIT_HMC5883L_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#include "i2c.h"

typedef struct
{
	float XAxis;
	float YAxis;
	float ZAxis;
} hmc5883l_scaled_t;

typedef struct
{
	int XAxis;
	int YAxis;
	int ZAxis;
} hmc5883l_raw_t;

struct hmc5883l_s
{
  //float _scale;
  float _fd;
  float _buffer[32];
  
  i2c_t * _i2c;
};

typedef struct hmc5883l_s hmc5883l_t;

hmc5883l_t * hmc5883l_create();
void hmc5883l_destroy(hmc5883l_t *);
float hmc5883l_heading(hmc5883l_t *);

#ifdef __cplusplus
}
#endif

#endif