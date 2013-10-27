/*
 
 i2c.c
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

#include "i2c.h"

i2c_t * i2c_alloc()
{
  i2c_t * obj;
  obj = calloc(1, sizeof(struct i2c_s));  
  return obj;
}

int i2c_init(i2c_t * obj, int addr)
{
  if(obj)
  {
    // open the i2c bus
    if ((obj->_fd = open("/dev/i2c-1", O_RDWR)) < 0)
    {
      printf("Failed to open /dev/i2c-1 bus.");
      exit(1); // ERROR HANDLING check errno to see what went wrong
    }  
    
    if (ioctl(obj->_fd, I2C_SLAVE, addr) < 0)
    {
      printf("Failed to acquire bus access to i2c slave.\n");
      exit(1); // ERROR HANDLING check errno to see what went wrong
    }
    
    obj->_addr = addr;
  }
  
  return 0;
}

void i2c_destroy(i2c_t * obj)
{
  if(obj)
  {
    if(obj->_fd)
      close(obj->_fd);
    
    free(obj);
  }
}

int i2c_read(i2c_t * obj, uint8_t * buffer, int length)
{
  return read(obj->_fd, buffer, length);
}

int i2c_write(i2c_t * obj, uint8_t * buffer, int length)
{
  return write(obj->_fd, buffer, length);
}