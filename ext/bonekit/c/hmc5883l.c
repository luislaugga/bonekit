/*
 
 hmc5883l.c
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

#include "hmc5883l.h"

#define HMC5883L_Address 0x1e

#define HMC5883L_Register_ConfigurationA 0x00
#define HMC5883L_Register_ConfigurationB 0x01
#define HMC5883L_Register_Mode           0x02
#define HMC5883L_Register_DataBegin      0x03

#define HMC5883L_Mode_Measurement_Continuous 0x00
#define HMC5883L_Mode_Measurement_SingleShot 0x01
#define HMC5883L_Mode_Measurement_Idle       0x03

#define ErrorCode_1 "Scalenotvalid"//Entered scale was not valid, valid gauss values are: 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1"
#define ErrorCode_1_Num 1

#include <math.h>

#define M_180_div_PI 57.2957795131
#define M_2PI 6.28318530718

hmc5883l_t * hmc5883l_create()
{
  hmc5883l_t * obj;
  obj = malloc(sizeof(struct hmc5883l_s));
  if(obj)
  {
    //obj->_scale = 1;
    
    // Initialize
    obj->_i2c = i2c_alloc();
    i2c_init(obj->_i2c, HMC5883L_Address);
  
    // Setup mode
    uint8_t setup[2] = {HMC5883L_Register_Mode, HMC5883L_Mode_Measurement_Continuous};
    i2c_write(obj->_i2c, setup, 2);
  }
  
  return obj;
}

void hmc5883l_destroy(hmc5883l_t * obj)
{
  if(obj)
  {
    i2c_destroy(obj->_i2c);
    free(obj); 
  }
}

float hmc5883l_heading(hmc5883l_t * obj)
{
  uint8_t write_data[1] = {HMC5883L_Register_DataBegin};
  uint8_t read_data[6];
  
  i2c_write(obj->_i2c, write_data, 1); // check if success before read
  i2c_read(obj->_i2c, read_data, 6); // check if success before calculate heading
    
  short x = (read_data[0] << 8) | read_data[1];
  short y = (read_data[4] << 8) | read_data[5];
  short z = (read_data[2] << 8) | read_data[3];
  
  float angle_radians = atan2(y,x);
  
  if(angle_radians < 0.0)
    angle_radians += M_2PI;
      
  float angle_degrees = angle_radians * M_180_div_PI;
  
  return angle_degrees;
}