/*
 
 i2c_class.c
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

#include "i2c_class.h"

#include "ruby.h"

#include "beaglebone.h"
#include "i2c.h"

VALUE cBoneKit_I2c;

static void I2c_free(i2c_t * ptr)
{
  if(ptr == NULL)
      return;

  i2c_destroy(ptr);
}

static VALUE I2c_alloc(VALUE class)
{
    i2c_t * ptr = i2c_alloc();
  
    VALUE self = Data_Wrap_Struct(class, 0, I2c_free, ptr);
    return self;
}

/*
 * call-seq:
 *  initialize(address) -> I2c
 *
 * Returns a new I2c object associated with a given address
 * @param [Integer] address the i2c slave address
 */
static VALUE I2c_initialize(int argc, VALUE* argv, VALUE self)
{
  if (argc > 1 || argc == 0)  // there should only 1 argument
    rb_raise(rb_eArgError, "wrong number of arguments (%d for 1)", argc);
  
  i2c_t * ptr;
  Data_Get_Struct(self, i2c_t, ptr);
  
  int address = NUM2INT(argv[0]);
  
  if(i2c_init(ptr, address) < 0) // check i2c bus and device address
    rb_raise(rb_eArgError, "I2c bus error");
  
  return self;
}

void BoneKit_I2c_class_init()
{
  cBoneKit_I2c = rb_define_class("I2c", rb_cObject);
  
  rb_define_alloc_func(cBoneKit_I2c, I2c_alloc);
  
  rb_define_method(cBoneKit_I2c, "initialize", I2c_initialize, -1);
}
