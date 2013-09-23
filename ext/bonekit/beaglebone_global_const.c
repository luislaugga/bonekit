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
  rb_define_global_const("USR0", UINT2NUM(USR0));
  rb_define_global_const("USR1", UINT2NUM(USR1));
  rb_define_global_const("USR2", UINT2NUM(USR2));
  rb_define_global_const("USR3", UINT2NUM(USR3));
  rb_define_global_const("P8_1", UINT2NUM(P8_1));
  rb_define_global_const("P8_2", UINT2NUM(P8_2));
  rb_define_global_const("P8_3", UINT2NUM(P8_3));
  rb_define_global_const("P8_4", UINT2NUM(P8_4));
  rb_define_global_const("P8_5", UINT2NUM(P8_5));
  rb_define_global_const("P8_6", UINT2NUM(P8_6));
  rb_define_global_const("P8_7", UINT2NUM(P8_7));
  rb_define_global_const("P8_8", UINT2NUM(P8_8));
  rb_define_global_const("P8_9", UINT2NUM(P8_9));
  rb_define_global_const("P8_10", UINT2NUM(P8_10));
  rb_define_global_const("P8_11", UINT2NUM(P8_11));
  rb_define_global_const("P8_12", UINT2NUM(P8_12));
  rb_define_global_const("P8_13", UINT2NUM(P8_13));
  rb_define_global_const("P8_14", UINT2NUM(P8_14));
  rb_define_global_const("P8_15", UINT2NUM(P8_15));
  rb_define_global_const("P8_16", UINT2NUM(P8_16));
  rb_define_global_const("P8_17", UINT2NUM(P8_17));
  rb_define_global_const("P8_18", UINT2NUM(P8_18));
  rb_define_global_const("P8_19", UINT2NUM(P8_19));
  rb_define_global_const("P8_20", UINT2NUM(P8_20));
  rb_define_global_const("P8_21", UINT2NUM(P8_21));
  rb_define_global_const("P8_22", UINT2NUM(P8_22));
  rb_define_global_const("P8_23", UINT2NUM(P8_23));
  rb_define_global_const("P8_24", UINT2NUM(P8_24));
  rb_define_global_const("P8_25", UINT2NUM(P8_25));
  rb_define_global_const("P8_26", UINT2NUM(P8_26));
  rb_define_global_const("P8_27", UINT2NUM(P8_27));
  rb_define_global_const("P8_28", UINT2NUM(P8_28));
  rb_define_global_const("P8_29", UINT2NUM(P8_29));
  rb_define_global_const("P8_30", UINT2NUM(P8_30));
  rb_define_global_const("P8_31", UINT2NUM(P8_31));
  rb_define_global_const("P8_32", UINT2NUM(P8_32));
  rb_define_global_const("P8_33", UINT2NUM(P8_33));
  rb_define_global_const("P8_34", UINT2NUM(P8_34));
  rb_define_global_const("P8_35", UINT2NUM(P8_35));
  rb_define_global_const("P8_36", UINT2NUM(P8_36));
  rb_define_global_const("P8_37", UINT2NUM(P8_37));
  rb_define_global_const("P8_38", UINT2NUM(P8_38));
  rb_define_global_const("P8_39", UINT2NUM(P8_39));
  rb_define_global_const("P8_40", UINT2NUM(P8_40));
  rb_define_global_const("P8_41", UINT2NUM(P8_41));
  rb_define_global_const("P8_42", UINT2NUM(P8_42));
  rb_define_global_const("P8_43", UINT2NUM(P8_43));
  rb_define_global_const("P8_44", UINT2NUM(P8_44));
  rb_define_global_const("P8_45", UINT2NUM(P8_45));
  rb_define_global_const("P8_46", UINT2NUM(P8_46));
  rb_define_global_const("P9_1", UINT2NUM(P9_1));
  rb_define_global_const("P9_2", UINT2NUM(P9_2));
  rb_define_global_const("P9_3", UINT2NUM(P9_3));
  rb_define_global_const("P9_4", UINT2NUM(P9_4));
  rb_define_global_const("P9_5", UINT2NUM(P9_5));
  rb_define_global_const("P9_6", UINT2NUM(P9_6));
  rb_define_global_const("P9_7", UINT2NUM(P9_7));
  rb_define_global_const("P9_8", UINT2NUM(P9_8));
  rb_define_global_const("P9_9", UINT2NUM(P9_9));
  rb_define_global_const("P9_10", UINT2NUM(P9_10));
  rb_define_global_const("P9_11", UINT2NUM(P9_11));
  rb_define_global_const("P9_12", UINT2NUM(P9_12));
  rb_define_global_const("P9_13", UINT2NUM(P9_13));
  rb_define_global_const("P9_14", UINT2NUM(P9_14));
  rb_define_global_const("P9_15", UINT2NUM(P9_15));
  rb_define_global_const("P9_16", UINT2NUM(P9_16));
  rb_define_global_const("P9_17", UINT2NUM(P9_17));
  rb_define_global_const("P9_18", UINT2NUM(P9_18));
  rb_define_global_const("P9_19", UINT2NUM(P9_19));
  rb_define_global_const("P9_20", UINT2NUM(P9_20));
  rb_define_global_const("P9_21", UINT2NUM(P9_21));
  rb_define_global_const("P9_22", UINT2NUM(P9_22));
  rb_define_global_const("P9_23", UINT2NUM(P9_23));
  rb_define_global_const("P9_24", UINT2NUM(P9_24));
  rb_define_global_const("P9_25", UINT2NUM(P9_25));
  rb_define_global_const("P9_26", UINT2NUM(P9_26));
  rb_define_global_const("P9_27", UINT2NUM(P9_27));
  rb_define_global_const("P9_28", UINT2NUM(P9_28));
  rb_define_global_const("P9_29", UINT2NUM(P9_29));
  rb_define_global_const("P9_30", UINT2NUM(P9_30));
  rb_define_global_const("P9_31", UINT2NUM(P9_31));
  rb_define_global_const("P9_32", UINT2NUM(P9_32));
  rb_define_global_const("P9_33", UINT2NUM(P9_33));
  rb_define_global_const("P9_34", UINT2NUM(P9_34));
  rb_define_global_const("P9_35", UINT2NUM(P9_35));
  rb_define_global_const("P9_36", UINT2NUM(P9_36));
  rb_define_global_const("P9_37", UINT2NUM(P9_37));
  rb_define_global_const("P9_38", UINT2NUM(P9_38));
  rb_define_global_const("P9_39", UINT2NUM(P9_39));
  rb_define_global_const("P9_40", UINT2NUM(P9_40));
  rb_define_global_const("P9_41", UINT2NUM(P9_41));
  rb_define_global_const("P9_42", UINT2NUM(P9_42));
  rb_define_global_const("P9_43", UINT2NUM(P9_43));
  rb_define_global_const("P9_44", UINT2NUM(P9_44));
  rb_define_global_const("P9_45", UINT2NUM(P9_45));
  rb_define_global_const("P9_46", UINT2NUM(P9_46));
}
