// #include "ruby.h"
// #include "pin.h"
// 
// VALUE class_pin;
// 
// static void class_pin_free(void * ptr)
// {
//   pin_destroy(ptr);
// }
// 
// VALUE class_pin_new(VALUE class, VALUE number)
// {
//   pin_t * ptr = pin_create(NUM2UINT(number));
//   VALUE tdata = Data_Wrap_Struct(class, 0, class_pin_free, ptr);
//   return tdata;
// }
// 
// static VALUE class_pin_value(VALUE self)
// {
//   pin_t * ptr;
//   Data_Get_Struct(self, pin_t, ptr);
//   return INT2NUM(pin_value(ptr));
// }
// 
// static void class_pin_set_value(VALUE self, VALUE value)
// {
//   pin_t * ptr;
//   Data_Get_Struct(self, pin_t, ptr);
//   pin_set_value(ptr, NUM2INT(value));
// }
// 
// void Init_pin()
// {
//   class_pin = rb_define_class("Pin", rb_cObject);
//   rb_define_singleton_method(class_pin, "new", class_pin_new, 1);
//   rb_define_method(class_pin, "value", class_pin_value, 0);
//   rb_define_method(class_pin, "value=", class_pin_set_value, 1);
// }