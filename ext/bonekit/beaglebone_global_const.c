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

#include "ruby.h"
#include "beaglebone.h"

void BoneKit_Beaglebone_global_const_init()
{  
  rb_define_global_const("USR0", INT2FIX(USR0));
  rb_define_global_const("USR1", INT2FIX(USR1));
  rb_define_global_const("USR2", INT2FIX(USR2));
  rb_define_global_const("USR3", INT2FIX(USR3));
  rb_define_global_const("P8_1", INT2FIX(P8_1));
  rb_define_global_const("P8_2", INT2FIX(P8_2));
  rb_define_global_const("P8_3", INT2FIX(P8_3));
  rb_define_global_const("P8_4", INT2FIX(P8_4));
  rb_define_global_const("P8_5", INT2FIX(P8_5));
  rb_define_global_const("P8_6", INT2FIX(P8_6));
  rb_define_global_const("P8_7", INT2FIX(P8_7));
  rb_define_global_const("P8_8", INT2FIX(P8_8));
  rb_define_global_const("P8_9", INT2FIX(P8_9));
  rb_define_global_const("P8_10", INT2FIX(P8_10));
  rb_define_global_const("P8_11", INT2FIX(P8_11));
  rb_define_global_const("P8_12", INT2FIX(P8_12));
  rb_define_global_const("P8_13", INT2FIX(P8_13));
  rb_define_global_const("P8_14", INT2FIX(P8_14));
  rb_define_global_const("P8_15", INT2FIX(P8_15));
  rb_define_global_const("P8_16", INT2FIX(P8_16));
  rb_define_global_const("P8_17", INT2FIX(P8_17));
  rb_define_global_const("P8_18", INT2FIX(P8_18));
  rb_define_global_const("P8_19", INT2FIX(P8_19));
  rb_define_global_const("P8_20", INT2FIX(P8_20));
  rb_define_global_const("P8_21", INT2FIX(P8_21));
  rb_define_global_const("P8_22", INT2FIX(P8_22));
  rb_define_global_const("P8_23", INT2FIX(P8_23));
  rb_define_global_const("P8_24", INT2FIX(P8_24));
  rb_define_global_const("P8_25", INT2FIX(P8_25));
  rb_define_global_const("P8_26", INT2FIX(P8_26));
  rb_define_global_const("P8_27", INT2FIX(P8_27));
  rb_define_global_const("P8_28", INT2FIX(P8_28));
  rb_define_global_const("P8_29", INT2FIX(P8_29));
  rb_define_global_const("P8_30", INT2FIX(P8_30));
  rb_define_global_const("P8_31", INT2FIX(P8_31));
  rb_define_global_const("P8_32", INT2FIX(P8_32));
  rb_define_global_const("P8_33", INT2FIX(P8_33));
  rb_define_global_const("P8_34", INT2FIX(P8_34));
  rb_define_global_const("P8_35", INT2FIX(P8_35));
  rb_define_global_const("P8_36", INT2FIX(P8_36));
  rb_define_global_const("P8_37", INT2FIX(P8_37));
  rb_define_global_const("P8_38", INT2FIX(P8_38));
  rb_define_global_const("P8_39", INT2FIX(P8_39));
  rb_define_global_const("P8_40", INT2FIX(P8_40));
  rb_define_global_const("P8_41", INT2FIX(P8_41));
  rb_define_global_const("P8_42", INT2FIX(P8_42));
  rb_define_global_const("P8_43", INT2FIX(P8_43));
  rb_define_global_const("P8_44", INT2FIX(P8_44));
  rb_define_global_const("P8_45", INT2FIX(P8_45));
  rb_define_global_const("P8_46", INT2FIX(P8_46));
  rb_define_global_const("P9_1", INT2FIX(P9_1));
  rb_define_global_const("P9_2", INT2FIX(P9_2));
  rb_define_global_const("P9_3", INT2FIX(P9_3));
  rb_define_global_const("P9_4", INT2FIX(P9_4));
  rb_define_global_const("P9_5", INT2FIX(P9_5));
  rb_define_global_const("P9_6", INT2FIX(P9_6));
  rb_define_global_const("P9_7", INT2FIX(P9_7));
  rb_define_global_const("P9_8", INT2FIX(P9_8));
  rb_define_global_const("P9_9", INT2FIX(P9_9));
  rb_define_global_const("P9_10", INT2FIX(P9_10));
  rb_define_global_const("P9_11", INT2FIX(P9_11));
  rb_define_global_const("P9_12", INT2FIX(P9_12));
  rb_define_global_const("P9_13", INT2FIX(P9_13));
  rb_define_global_const("P9_14", INT2FIX(P9_14));
  rb_define_global_const("P9_15", INT2FIX(P9_15));
  rb_define_global_const("P9_16", INT2FIX(P9_16));
  rb_define_global_const("P9_17", INT2FIX(P9_17));
  rb_define_global_const("P9_18", INT2FIX(P9_18));
  rb_define_global_const("P9_19", INT2FIX(P9_19));
  rb_define_global_const("P9_20", INT2FIX(P9_20));
  rb_define_global_const("P9_21", INT2FIX(P9_21));
  rb_define_global_const("P9_22", INT2FIX(P9_22));
  rb_define_global_const("P9_23", INT2FIX(P9_23));
  rb_define_global_const("P9_24", INT2FIX(P9_24));
  rb_define_global_const("P9_25", INT2FIX(P9_25));
  rb_define_global_const("P9_26", INT2FIX(P9_26));
  rb_define_global_const("P9_27", INT2FIX(P9_27));
  rb_define_global_const("P9_28", INT2FIX(P9_28));
  rb_define_global_const("P9_29", INT2FIX(P9_29));
  rb_define_global_const("P9_30", INT2FIX(P9_30));
  rb_define_global_const("P9_31", INT2FIX(P9_31));
  rb_define_global_const("P9_32", INT2FIX(P9_32));
  rb_define_global_const("P9_33", INT2FIX(P9_33));
  rb_define_global_const("P9_34", INT2FIX(P9_34));
  rb_define_global_const("P9_35", INT2FIX(P9_35));
  rb_define_global_const("P9_36", INT2FIX(P9_36));
  rb_define_global_const("P9_37", INT2FIX(P9_37));
  rb_define_global_const("P9_38", INT2FIX(P9_38));
  rb_define_global_const("P9_39", INT2FIX(P9_39));
  rb_define_global_const("P9_40", INT2FIX(P9_40));
  rb_define_global_const("P9_41", INT2FIX(P9_41));
  rb_define_global_const("P9_42", INT2FIX(P9_42));
  rb_define_global_const("P9_43", INT2FIX(P9_43));
  rb_define_global_const("P9_44", INT2FIX(P9_44));
  rb_define_global_const("P9_45", INT2FIX(P9_45));
  rb_define_global_const("P9_46", INT2FIX(P9_46));
}
