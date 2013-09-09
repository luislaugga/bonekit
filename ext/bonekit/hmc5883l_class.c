#include "ruby.h"
#include "hmc5883l.h"

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

void Init_bonekit()
{
  class_hmc5883l = rb_define_class("HMC5883L", rb_cObject);
  rb_define_singleton_method(class_hmc5883l, "new", class_hmc5883l_new, 0);
  rb_define_method(class_hmc5883l, "heading", class_hmc5883l_heading, 0);
}