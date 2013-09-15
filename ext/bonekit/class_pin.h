/*
 
 pin.h
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

#ifndef BONEKIT_CLASS_PIN_H__
#define BONEKIT_CLASS_PIN_H__

#include "ruby.h"
#include "pin.h"
#include "gpio.h"

VALUE class_pin;

static void class_pin_free(void * ptr)
{
  pin_destroy(ptr);
}

VALUE class_pin_new(int argc, VALUE* argv, VALUE self)
{
  if (argc > 2 || argc == 0)  // there should only be 1 or 2 arguments
    rb_raise(rb_eArgError, "Wrong number of arguments");
  
  pin_t * ptr = pin_create(NUM2UINT(argv[0]));
  
  int mode = INPUT;
  
  if(argc == 2)
    mode = NUM2INT(argv[1]);

  pin_set_mode(ptr, mode);
  
  VALUE wrap_struct = Data_Wrap_Struct(self, 0, class_pin_free, ptr);
  return wrap_struct;
}

static VALUE class_pin_value(VALUE self)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  return INT2NUM(pin_value(ptr));
}

static void class_pin_set_value(VALUE self, VALUE value)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  pin_set_value(ptr, NUM2INT(value));
}

static VALUE class_pin_mode(VALUE self)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  return INT2NUM(pin_mode(ptr));
}

static void class_pin_set_mode(VALUE self, VALUE value)
{
  pin_t * ptr;
  Data_Get_Struct(self, pin_t, ptr);
  pin_set_mode(ptr, NUM2INT(value));
}

void bonekit_class_pin_init()
{
  class_pin = rb_define_class("Pin", rb_cObject);
  rb_define_singleton_method(class_pin, "new", class_pin_new, -1); // Pin#new(number,mode=Input)
  rb_define_method(class_pin, "value", class_pin_value, 0);
  rb_define_method(class_pin, "value=", class_pin_set_value, 1);
  rb_define_method(class_pin, "mode", class_pin_mode, 0);
  rb_define_method(class_pin, "mode=", class_pin_set_mode, 1);
  
  rb_define_global_const("High", INT2NUM(HIGH));
  rb_define_global_const("Low", INT2NUM(LOW));
  rb_define_global_const("Input", INT2NUM(INPUT));
  rb_define_global_const("Output", INT2NUM(OUTPUT));
}

#endif