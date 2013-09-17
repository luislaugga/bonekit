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

#define M_PI 3.14159265358979323846

void selectDevice(int fd, int addr, char * name)
{
  if (ioctl(fd, I2C_SLAVE, addr) < 0)
  {
    fprintf(stderr, "%s not present\n", name);
    exit(1);
  }
}

void writeToDevice(int fd, int reg, int val)
{
  char buf[2];
  buf[0]=reg;
  buf[1]=val;
  
  if (write(fd, buf, 2) != 2)
  {
    fprintf(stderr, "Can't write to device\n");
  }
}

void readFromDevice(int fd, uint8_t * buf, int len)
{
  int readRegister = 0x03;
  if((write(fd, &readRegister, 1)) != 1)
  {
    //error
  }
  else
  {
    if(read(fd, buf, len) != len)
    {
      //error
    }
  }
}

hmc5883l_t * hmc5883l_create()
{
  hmc5883l_t * obj;
  obj = malloc(sizeof(struct hmc5883l_s));
  if(obj)
  {
    obj->_scale = 1;
  
    if ((obj->_fd = open("/dev/i2c-1", O_RDWR)) < 0)
    {
      // Open port for reading and writing
      //printf("HMC5883L::Failed to open i2c bus\n");
    }

    selectDevice(obj->_fd, HMC5883L_Address, HMC5883L_Name);
    writeToDevice(obj->_fd, ModeRegister, Measurement_Continuous);
  }
  
  return obj;
}

void hmc5883l_destroy(hmc5883l_t * obj)
{
  free(obj);
}

float hmc5883l_heading(hmc5883l_t * obj)
{
  unsigned char buf[16];
  readFromDevice(obj->_fd, buf, 6);
  
  short x = (buf[0] << 8) | buf[1];
  short y = (buf[4] << 8) | buf[5];
  short z = (buf[2] << 8) | buf[3];
  
  float angle = atan2(y, x) * 180 / M_PI;
  
  return angle;
}