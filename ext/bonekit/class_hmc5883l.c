/*
 
 class_hmc5883l.c
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

#include "class_hmc5883l.h"

#include "ruby.h"
#include "hmc5883l.h"

VALUE class_hmc5883l;

static void class_hmc5883l_free(void * ptr)
{
  hmc5883l_destroy(ptr);
}

static VALUE class_hmc5883l_new(VALUE class)
{
  hmc5883l_t * ptr = hmc5883l_create();
  VALUE wrap_struct = Data_Wrap_Struct(class, 0, class_hmc5883l_free, ptr);
  return wrap_struct;
}

static VALUE class_hmc5883l_heading(VALUE self)
{
  double value = 0.0f;
  hmc5883l_t * ptr;
  Data_Get_Struct(self, hmc5883l_t, ptr);
  value = hmc5883l_heading(ptr);
  return rb_float_new(value);
}

void bonekit_class_hmc5883l_init()
{
  class_hmc5883l = rb_define_class("HMC5883L", rb_cObject);
  rb_define_singleton_method(class_hmc5883l, "new", class_hmc5883l_new, 0);
  rb_define_method(class_hmc5883l, "heading", class_hmc5883l_heading, 0);
}
