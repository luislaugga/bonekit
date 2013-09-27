/*
 
 beaglebone_global_const.c
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

#include "beaglebone_global_const.h"

VALUE cBoneKit_BeaglebonePin;

int Beaglebone_global_const_check_type(VALUE self)
{
  return rb_obj_is_kind_of(self, cBoneKit_BeaglebonePin);
}

beaglebone_t * Beaglebone_global_const_to_beaglebone_t(VALUE self)
{
  beaglebone_t * ptr;
  Data_Get_Struct(self, beaglebone_t, ptr);
  return ptr;
}

static void Beaglebone_global_const_free(void * ptr)
{
  if(ptr == NULL)
      return;
  
  free(ptr);
}

static VALUE Beaglebone_global_const_new(VALUE class, beaglebone_t beaglebone_pin)
{
  beaglebone_t * ptr = calloc(1, sizeof(beaglebone_t));
  memcpy(ptr, &beaglebone_pin, sizeof(beaglebone_t));
  
  VALUE self = Data_Wrap_Struct(class, 0, Beaglebone_global_const_free, ptr);
  return self;
}

void BoneKit_Beaglebone_global_const_init()
{  
  cBoneKit_BeaglebonePin = rb_define_class("BeaglebonePin", rb_cObject);
  
  rb_define_global_const("USR0", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, USR0));
  rb_define_global_const("USR1", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, USR1));
  rb_define_global_const("USR2", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, USR2));
  rb_define_global_const("USR3", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, USR3));
  rb_define_global_const("P8_1", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_1));
  rb_define_global_const("P8_2", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_2));
  rb_define_global_const("P8_3", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_3));
  rb_define_global_const("P8_4", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_4));
  rb_define_global_const("P8_5", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_5));
  rb_define_global_const("P8_6", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_6));
  rb_define_global_const("P8_7", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_7));
  rb_define_global_const("P8_8", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_8));
  rb_define_global_const("P8_9", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_9));
  rb_define_global_const("P8_10", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_10));
  rb_define_global_const("P8_11", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_11));
  rb_define_global_const("P8_12", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_12));
  rb_define_global_const("P8_13", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_13));
  rb_define_global_const("P8_14", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_14));
  rb_define_global_const("P8_15", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_15));
  rb_define_global_const("P8_16", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_16));
  rb_define_global_const("P8_17", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_17));
  rb_define_global_const("P8_18", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_18));
  rb_define_global_const("P8_19", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_19));
  rb_define_global_const("P8_20", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_20));
  rb_define_global_const("P8_21", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_21));
  rb_define_global_const("P8_22", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_22));
  rb_define_global_const("P8_23", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_23));
  rb_define_global_const("P8_24", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_24));
  rb_define_global_const("P8_25", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_25));
  rb_define_global_const("P8_26", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_26));
  rb_define_global_const("P8_27", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_27));
  rb_define_global_const("P8_28", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_28));
  rb_define_global_const("P8_29", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_29));
  rb_define_global_const("P8_30", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_30));
  rb_define_global_const("P8_31", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_31));
  rb_define_global_const("P8_32", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_32));
  rb_define_global_const("P8_33", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_33));
  rb_define_global_const("P8_34", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_34));
  rb_define_global_const("P8_35", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_35));
  rb_define_global_const("P8_36", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_36));
  rb_define_global_const("P8_37", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_37));
  rb_define_global_const("P8_38", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_38));
  rb_define_global_const("P8_39", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_39));
  rb_define_global_const("P8_40", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_40));
  rb_define_global_const("P8_41", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_41));
  rb_define_global_const("P8_42", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_42));
  rb_define_global_const("P8_43", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_43));
  rb_define_global_const("P8_44", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_44));
  rb_define_global_const("P8_45", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_45));
  rb_define_global_const("P8_46", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P8_46));
  rb_define_global_const("P9_1", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_1));
  rb_define_global_const("P9_2", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_2));
  rb_define_global_const("P9_3", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_3));
  rb_define_global_const("P9_4", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_4));
  rb_define_global_const("P9_5", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_5));
  rb_define_global_const("P9_6", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_6));
  rb_define_global_const("P9_7", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_7));
  rb_define_global_const("P9_8", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_8));
  rb_define_global_const("P9_9", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_9));
  rb_define_global_const("P9_10", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_10));
  rb_define_global_const("P9_11", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_11));
  rb_define_global_const("P9_12", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_12));
  rb_define_global_const("P9_13", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_13));
  rb_define_global_const("P9_14", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_14));
  rb_define_global_const("P9_15", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_15));
  rb_define_global_const("P9_16", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_16));
  rb_define_global_const("P9_17", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_17));
  rb_define_global_const("P9_18", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_18));
  rb_define_global_const("P9_19", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_19));
  rb_define_global_const("P9_20", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_20));
  rb_define_global_const("P9_21", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_21));
  rb_define_global_const("P9_22", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_22));
  rb_define_global_const("P9_23", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_23));
  rb_define_global_const("P9_24", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_24));
  rb_define_global_const("P9_25", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_25));
  rb_define_global_const("P9_26", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_26));
  rb_define_global_const("P9_27", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_27));
  rb_define_global_const("P9_28", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_28));
  rb_define_global_const("P9_29", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_29));
  rb_define_global_const("P9_30", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_30));
  rb_define_global_const("P9_31", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_31));
  rb_define_global_const("P9_32", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_32));
  rb_define_global_const("P9_33", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_33));
  rb_define_global_const("P9_34", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_34));
  rb_define_global_const("P9_35", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_35));
  rb_define_global_const("P9_36", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_36));
  rb_define_global_const("P9_37", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_37));
  rb_define_global_const("P9_38", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_38));
  rb_define_global_const("P9_39", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_39));
  rb_define_global_const("P9_40", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_40));
  rb_define_global_const("P9_41", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_41));
  rb_define_global_const("P9_42", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_42));
  rb_define_global_const("P9_43", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_43));
  rb_define_global_const("P9_44", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_44));
  rb_define_global_const("P9_45", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_45));
  rb_define_global_const("P9_46", Beaglebone_global_const_new(cBoneKit_BeaglebonePin, P9_46));
}
