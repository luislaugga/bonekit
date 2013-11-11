/*
 
 adxl345_class.h
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

#include "adxl345_class.h"

#include "ruby.h"
#include "bonekit.h"

VALUE cBoneKit_ADXL345;

static void ADXL345_free(void * ptr)
{
  if(ptr == NULL)
      return;

  adxl345_destroy(ptr);
}

/*
 * call-seq:
 *  initialize() -> ADXL345
 *
 * Returns a new ADXL345 object. 
 */
static VALUE ADXL345_new(VALUE class)
{
  adxl345_t * ptr = adxl345_create();
  VALUE wrap_struct = Data_Wrap_Struct(class, 0, ADXL345_free, ptr);
  return wrap_struct;
}

/*
 * call-seq:
 *  raw_acceleration() -> Array
 *
 * Returns an Array with the raw acceleration values ([x,y,z]). 
 * The ADXL345 is pre-configured for measuring values in the +/-4g range.
 */
static VALUE ADXL345_raw_acceleration(VALUE self)
{
  adxl345_t * ptr;
  Data_Get_Struct(self, adxl345_t, ptr);
  
  adxl345_vec3_raw_t * raw_acceleration = adxl345_raw_acceleration(ptr);
  
  VALUE value = rb_ary_new2(3);
  
  rb_ary_push(value, INT2FIX(raw_acceleration->x));
  rb_ary_push(value, INT2FIX(raw_acceleration->y));
  rb_ary_push(value, INT2FIX(raw_acceleration->z));
  
  return value;
}

void BoneKit_ADXL345_class_init()
{
  cBoneKit_ADXL345 = rb_define_class("ADXL345", rb_cObject);
  
  rb_define_singleton_method(cBoneKit_ADXL345, "new", ADXL345_new, 0);
  
  rb_define_method(cBoneKit_ADXL345, "raw_acceleration", ADXL345_raw_acceleration, 0);
}
