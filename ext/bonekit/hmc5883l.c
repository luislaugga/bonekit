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

#define BONEKIT_DEVICE_HMC5883L_Address 0x1E

#define ConfigurationRegisterA 0x00
#define ConfigurationRegisterB 0x01

#define ModeRegister 0x02
#define DataRegisterBegin 0x03

#define Measurement_Continuous 0x00
#define Measurement_SingleShot 0x01
#define Measurement_Idle 0x03

#define ErrorCode_1 "Scalenotvalid"//Entered scale was not valid, valid gauss values are: 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1"
#define ErrorCode_1_Num 1

#include <math.h>

#define M_PI 3.14159265358979323846

// void selectDevice(int fd, int addr, char * name)
// {
//   if (ioctl(fd, I2C_SLAVE, addr) < 0)
//   {
//     fprintf(stderr, "%s not present\n", name);
//     exit(1);
//   }
// }
// 
// void writeToDevice(int fd, int reg, int val)
// {
//   char buf[2];
//   buf[0]=reg;
//   buf[1]=val;
//   
//   if (write(fd, buf, 2) != 2)
//   {
//     fprintf(stderr, "Can't write to device\n");
//   }
// }
// 
// void readFromDevice(int fd, uint8_t * buf, int len)
// {
//   int readRegister = 0x03;
//   if((write(fd, &readRegister, 1)) != 1)
//   {
//     //error
//   }
//   else
//   {
//     if(read(fd, buf, len) != len)
//     {
//       //error
//     }
//   }
// }

hmc5883l_t * hmc5883l_create()
{
  hmc5883l_t * obj;
  obj = malloc(sizeof(struct hmc5883l_s));
  if(obj)
  {
    obj->_scale = 1;
    
    obj->_i2c = i2c_alloc();
    i2c_init(obj->_i2c, BONEKIT_DEVICE_HMC5883L_Address);
  
    uint8_t setup[2] = {ModeRegister, Measurement_Continuous};
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
  uint8_t data[6];
  
  uint8_t readRegister = 0x03;
  i2c_write(obj->_i2c, &readRegister, 1); // check if success before read
  i2c_read(obj->_i2c, data, 6); // check if success before calculate heading
    
  short x = (data[0] << 8) | data[1];
  short y = (data[4] << 8) | data[5];
  short z = (data[2] << 8) | data[3];
  
  float angle = atan2(y, x) * 180 / M_PI;
  
  return angle;
}