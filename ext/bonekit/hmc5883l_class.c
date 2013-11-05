/*
 
 hmc5883l_class.h
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

#include "hmc5883l_class.h"

#include "ruby.h"
#include "bonekit.h"

VALUE cBoneKit_HMC5883L;

static void HMC5883L_free(void * ptr)
{
  if(ptr == NULL)
      return;

  hmc5883l_destroy(ptr);
}

static VALUE HMC5883L_new(VALUE class)
{
  hmc5883l_t * ptr = hmc5883l_create();
  VALUE wrap_struct = Data_Wrap_Struct(class, 0, HMC5883L_free, ptr);
  return wrap_struct;
}

static VALUE HMC5883L_heading(VALUE self)
{
  double value = 0.0f;
  hmc5883l_t * ptr;
  Data_Get_Struct(self, hmc5883l_t, ptr);
  value = hmc5883l_heading(ptr);
  return rb_float_new(value);
}

void BoneKit_HMC5883L_class_init()
{
  cBoneKit_HMC5883L = rb_define_class("HMC5883L", rb_cObject);
  
  rb_define_singleton_method(cBoneKit_HMC5883L, "new", HMC5883L_new, 0);
  
  rb_define_method(cBoneKit_HMC5883L, "heading", HMC5883L_heading, 0);
}
