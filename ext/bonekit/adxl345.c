/*
 
 adxl345.c
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

#include "adxl345.h"

#define ADXL345_Address 0x53

#define ADXL345_Register_Power_Control 0x2d
#define ADXL345_Register_Data_Format   0x31
#define ADXL345_Register_Data_Begin    0x32

#define ADXL345_Mode_Measurement 0x08 // Register 0x2D—POWER_CTL (Read/Write), Measure bit (D3) set to 1, 0b00001000
#define ADXL345_Mode_Range_4G    0x01 // Register 0x31—DATA_FORMAT (Read/Write), Range bits (D0-D1) set to 1, 0x00000001

#include <math.h>

#define M_180_div_PI 57.2957795131
#define M_2PI 6.28318530718

adxl345_t * adxl345_create()
{
  adxl345_t * obj;
  obj = malloc(sizeof(struct adxl345_s));
  if(obj)
  {
    // Initialize
    obj->_i2c = i2c_alloc();
    i2c_init(obj->_i2c, ADXL345_Address);
  
    // Setup mode
    uint8_t data_setup[2] = {ADXL345_Register_Data_Format, ADXL345_Mode_Range_4G};
    i2c_write(obj->_i2c, data_setup, 2);
    uint8_t power_setup[2] = {ADXL345_Register_Power_Control, ADXL345_Mode_Measurement};
    i2c_write(obj->_i2c, power_setup, 2);
  }
  
  return obj;
}

void adxl345_destroy(adxl345_t * obj)
{
  if(obj)
  {
    i2c_destroy(obj->_i2c);
    free(obj); 
  }
}

adxl345_vec3_raw_t * adxl345_raw_acceleration(adxl345_t * obj)
{
  uint8_t write_data[1] = {ADXL345_Register_Data_Begin};
  uint8_t read_data[6];
  
  i2c_write(obj->_i2c, write_data, 1); // check if success before read
  i2c_read(obj->_i2c, read_data, 6); // check if success before calculate heading
    
  int x = (read_data[1] << 8) | read_data[0];
  int y = (read_data[3] << 8) | read_data[2];
  int z = (read_data[5] << 8) | read_data[4];
  
  obj->_raw_acceleration.x = x;
  obj->_raw_acceleration.y = y;
  obj->_raw_acceleration.z = z;

  return &(obj->_raw_acceleration);
}