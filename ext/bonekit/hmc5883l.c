/*
 
 hmc5883l.c
 BoneKit
 
 Copyright (cc) 2012 Luis Laugga.
 Some rights reserved, all wrongs deserved.
 
 Licensed under a Creative Commons Attribution-ShareAlike 3.0 License;
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://creativecommons.org/licenses/by-sa/3.0/
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" basis,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
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