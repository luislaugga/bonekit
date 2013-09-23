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
  rb_define_global_const("USR0", INT2NUM(USR0));
  rb_define_global_const("USR1", INT2NUM(USR1));
  rb_define_global_const("USR2", INT2NUM(USR2));
  rb_define_global_const("USR3", INT2NUM(USR3));
  rb_define_global_const("P8_1", INT2NUM(P8_1));
  rb_define_global_const("P8_2", INT2NUM(P8_2));
  rb_define_global_const("P8_3", INT2NUM(P8_3));
  rb_define_global_const("P8_4", INT2NUM(P8_4));
  rb_define_global_const("P8_5", INT2NUM(P8_5));
  rb_define_global_const("P8_6", INT2NUM(P8_6));
  rb_define_global_const("P8_7", INT2NUM(P8_7));
  rb_define_global_const("P8_8", INT2NUM(P8_8));
  rb_define_global_const("P8_9", INT2NUM(P8_9));
  rb_define_global_const("P8_10", INT2NUM(P8_10));
  rb_define_global_const("P8_11", INT2NUM(P8_11));
  rb_define_global_const("P8_12", INT2NUM(P8_12));
  rb_define_global_const("P8_13", INT2NUM(P8_13));
  rb_define_global_const("P8_14", INT2NUM(P8_14));
  rb_define_global_const("P8_15", INT2NUM(P8_15));
  rb_define_global_const("P8_16", INT2NUM(P8_16));
  rb_define_global_const("P8_17", INT2NUM(P8_17));
  rb_define_global_const("P8_18", INT2NUM(P8_18));
  rb_define_global_const("P8_19", INT2NUM(P8_19));
  rb_define_global_const("P8_20", INT2NUM(P8_20));
  rb_define_global_const("P8_21", INT2NUM(P8_21));
  rb_define_global_const("P8_22", INT2NUM(P8_22));
  rb_define_global_const("P8_23", INT2NUM(P8_23));
  rb_define_global_const("P8_24", INT2NUM(P8_24));
  rb_define_global_const("P8_25", INT2NUM(P8_25));
  rb_define_global_const("P8_26", INT2NUM(P8_26));
  rb_define_global_const("P8_27", INT2NUM(P8_27));
  rb_define_global_const("P8_28", INT2NUM(P8_28));
  rb_define_global_const("P8_29", INT2NUM(P8_29));
  rb_define_global_const("P8_30", INT2NUM(P8_30));
  rb_define_global_const("P8_31", INT2NUM(P8_31));
  rb_define_global_const("P8_32", INT2NUM(P8_32));
  rb_define_global_const("P8_33", INT2NUM(P8_33));
  rb_define_global_const("P8_34", INT2NUM(P8_34));
  rb_define_global_const("P8_35", INT2NUM(P8_35));
  rb_define_global_const("P8_36", INT2NUM(P8_36));
  rb_define_global_const("P8_37", INT2NUM(P8_37));
  rb_define_global_const("P8_38", INT2NUM(P8_38));
  rb_define_global_const("P8_39", INT2NUM(P8_39));
  rb_define_global_const("P8_40", INT2NUM(P8_40));
  rb_define_global_const("P8_41", INT2NUM(P8_41));
  rb_define_global_const("P8_42", INT2NUM(P8_42));
  rb_define_global_const("P8_43", INT2NUM(P8_43));
  rb_define_global_const("P8_44", INT2NUM(P8_44));
  rb_define_global_const("P8_45", INT2NUM(P8_45));
  rb_define_global_const("P8_46", INT2NUM(P8_46));
  rb_define_global_const("P9_1", INT2NUM(P9_1));
  rb_define_global_const("P9_2", INT2NUM(P9_2));
  rb_define_global_const("P9_3", INT2NUM(P9_3));
  rb_define_global_const("P9_4", INT2NUM(P9_4));
  rb_define_global_const("P9_5", INT2NUM(P9_5));
  rb_define_global_const("P9_6", INT2NUM(P9_6));
  rb_define_global_const("P9_7", INT2NUM(P9_7));
  rb_define_global_const("P9_8", INT2NUM(P9_8));
  rb_define_global_const("P9_9", INT2NUM(P9_9));
  rb_define_global_const("P9_10", INT2NUM(P9_10));
  rb_define_global_const("P9_11", INT2NUM(P9_11));
  rb_define_global_const("P9_12", INT2NUM(P9_12));
  rb_define_global_const("P9_13", INT2NUM(P9_13));
  rb_define_global_const("P9_14", INT2NUM(P9_14));
  rb_define_global_const("P9_15", INT2NUM(P9_15));
  rb_define_global_const("P9_16", INT2NUM(P9_16));
  rb_define_global_const("P9_17", INT2NUM(P9_17));
  rb_define_global_const("P9_18", INT2NUM(P9_18));
  rb_define_global_const("P9_19", INT2NUM(P9_19));
  rb_define_global_const("P9_20", INT2NUM(P9_20));
  rb_define_global_const("P9_21", INT2NUM(P9_21));
  rb_define_global_const("P9_22", INT2NUM(P9_22));
  rb_define_global_const("P9_23", INT2NUM(P9_23));
  rb_define_global_const("P9_24", INT2NUM(P9_24));
  rb_define_global_const("P9_25", INT2NUM(P9_25));
  rb_define_global_const("P9_26", INT2NUM(P9_26));
  rb_define_global_const("P9_27", INT2NUM(P9_27));
  rb_define_global_const("P9_28", INT2NUM(P9_28));
  rb_define_global_const("P9_29", INT2NUM(P9_29));
  rb_define_global_const("P9_30", INT2NUM(P9_30));
  rb_define_global_const("P9_31", INT2NUM(P9_31));
  rb_define_global_const("P9_32", INT2NUM(P9_32));
  rb_define_global_const("P9_33", INT2NUM(P9_33));
  rb_define_global_const("P9_34", INT2NUM(P9_34));
  rb_define_global_const("P9_35", INT2NUM(P9_35));
  rb_define_global_const("P9_36", INT2NUM(P9_36));
  rb_define_global_const("P9_37", INT2NUM(P9_37));
  rb_define_global_const("P9_38", INT2NUM(P9_38));
  rb_define_global_const("P9_39", INT2NUM(P9_39));
  rb_define_global_const("P9_40", INT2NUM(P9_40));
  rb_define_global_const("P9_41", INT2NUM(P9_41));
  rb_define_global_const("P9_42", INT2NUM(P9_42));
  rb_define_global_const("P9_43", INT2NUM(P9_43));
  rb_define_global_const("P9_44", INT2NUM(P9_44));
  rb_define_global_const("P9_45", INT2NUM(P9_45));
  rb_define_global_const("P9_46", INT2NUM(P9_46));
}
