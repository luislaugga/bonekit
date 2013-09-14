#include "ruby.h"
#include "pin.h"
#include "gpio.h"
#include "hmc5883l.h"

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
  
  VALUE tdata = Data_Wrap_Struct(self, 0, class_pin_free, ptr);
  return tdata;
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

void Bonekit_Pin_class_init()
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

VALUE class_hmc5883l;

static void class_hmc5883l_free(void * ptr)
{
  hmc5883l_destroy(ptr);
}

VALUE class_hmc5883l_new(VALUE class)
{
  hmc5883l_t * ptr = hmc5883l_create();
  VALUE tdata = Data_Wrap_Struct(class, 0, class_hmc5883l_free, ptr);
  return tdata;
}

static VALUE class_hmc5883l_heading(VALUE self)
{
  double value = 0.0f;
  hmc5883l_t * ptr;
  Data_Get_Struct(self, hmc5883l_t, ptr);
  value = hmc5883l_heading(ptr);
  return rb_float_new(value);
}

void Bonekit_HMC5883L_class_init()
{
  class_hmc5883l = rb_define_class("HMC5883L", rb_cObject);
  rb_define_singleton_method(class_hmc5883l, "new", class_hmc5883l_new, 0);
  rb_define_method(class_hmc5883l, "heading", class_hmc5883l_heading, 0);
}


void Init_bonekit(void)
{
  Bonekit_Pin_class_init();
  Bonekit_HMC5883L_class_init();
}