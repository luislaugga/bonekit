/*
 
 pin_class.c
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

#include "pin_class.h"

#include "ruby.h"
#include "gpio.h"
#include "pin.h"

VALUE cBoneKit_Pin;

static void Pin_free(pin_t * ptr)
{
  if(ptr == NULL)
      return;

  pin_destroy(ptr);
}

static VALUE Pin_alloc(VALUE class)
{
    pin_t * ptr = pin_alloc();
  
    VALUE self = Data_Wrap_Struct(class, 0, Pin_free, ptr);
    return self;
}

/*
 * call-seq:
 *  initialize(pin, mode=Input) -> Pin
 *
 * Returns a new Pin object with default value of 0
 * @param [Integer] pin the pin number
 * @param [Integer] mode the pin mode to be used (Input or Output)
 */
static VALUE Pin_initialize(int argc, VALUE* argv, VALUE self)
{
  if (argc > 2 || argc == 0)  // there should only be 1 or 2 arguments
    rb_raise(rb_eArgError, "wrong number of arguments (%d for 0..1)", argc);
  
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  
  pin_init(ptr, NUM2UINT(argv[0]));
  
  int mode = INPUT;
  
  if(argc == 2)
    mode = NUM2INT(argv[1]);

  pin_set_mode(ptr, mode);
  
  return self;
}

/*
 * call-seq:
 *  value -> integer
 *
 * Reads the value from the pin.
 */
static VALUE Pin_value(VALUE self)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  
  return INT2NUM(pin_value(ptr));
}

/*
 * call-seq:
 *  value=(value) -> integer
 *
 * Write the value to the pin. The pin mode must be set to Output.
 * Possible values: High, Low.
 */
static VALUE Pin_set_value(VALUE self, VALUE value)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  pin_set_value(ptr, NUM2INT(value));
  
  return value;
}

/*
 * call-seq:
 *  mode -> integer
 *
 * Returns the mode of the pin.
 * Possible modes: Input, Output.
 */
static VALUE Pin_mode(VALUE self)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  return INT2NUM(pin_mode(ptr));
}

/*
 * call-seq:
 *  mode=(mode) -> integer
 *
 * Sets the mode of the pin.
 * Possible modes: Input, Output.
 */
static VALUE Pin_set_mode(VALUE self, VALUE value)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  pin_set_mode(ptr, NUM2INT(value));
  
  return value;
}

void BoneKit_Pin_class_init()
{
  cBoneKit_Pin = rb_define_class("Pin", rb_cObject);
  
  rb_define_alloc_func(cBoneKit_Pin, Pin_alloc);
  
  rb_define_method(cBoneKit_Pin, "initialize", Pin_initialize, -1);
  rb_define_method(cBoneKit_Pin, "value", Pin_value, 0);
  rb_define_method(cBoneKit_Pin, "value=", Pin_set_value, 1);
  rb_define_method(cBoneKit_Pin, "mode", Pin_mode, 0);
  rb_define_method(cBoneKit_Pin, "mode=", Pin_set_mode, 1);
  
  rb_define_global_const("High", INT2NUM(HIGH));
  rb_define_global_const("Low", INT2NUM(LOW));
  rb_define_global_const("Input", INT2NUM(INPUT));
  rb_define_global_const("Output", INT2NUM(OUTPUT));
}
