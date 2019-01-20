#include "ruby.h"
#include "rubyspec.h"

#ifdef __cplusplus
extern "C" {
#endif

static VALUE numeric_spec_size_of_VALUE(VALUE self) {
  return INT2FIX(sizeof(VALUE));
}

static VALUE numeric_spec_size_of_long_long(VALUE self) {
  return INT2FIX(sizeof(LONG_LONG));
}

static VALUE numeric_spec_NUM2CHR(VALUE self, VALUE value) {
  return INT2FIX(NUM2CHR(value));
}

static VALUE numeric_spec_rb_int2inum_14(VALUE self) {
  return rb_int2inum(14);
}

static VALUE numeric_spec_rb_uint2inum_14(VALUE self) {
  return rb_uint2inum(14);
}

static VALUE numeric_spec_rb_uint2inum_n14(VALUE self) {
  return rb_uint2inum(-14);
}

static VALUE numeric_spec_rb_Integer(VALUE self, VALUE str) {
  return rb_Integer(str);
}

static VALUE numeric_spec_rb_ll2inum_14(VALUE self) {
  return rb_ll2inum(14);
}

static VALUE numeric_spec_rb_ull2inum_14(VALUE self) {
  return rb_ull2inum(14);
}

static VALUE numeric_spec_rb_ull2inum_n14(VALUE self) {
  return rb_ull2inum(-14);
}

static VALUE numeric_spec_rb_num2dbl(VALUE self, VALUE num) {
  return rb_float_new(rb_num2dbl(num));
}

#if SIZEOF_INT < SIZEOF_LONG
static VALUE numeric_spec_rb_num2int(VALUE self, VALUE num) {
  return LONG2NUM(rb_num2int(num));
}
#endif

static VALUE numeric_spec_rb_int2num(VALUE self, VALUE num) {
  return INT2NUM(rb_num2long(num));
}

static VALUE numeric_spec_rb_num2long(VALUE self, VALUE num) {
  return LONG2NUM(rb_num2long(num));
}

#if SIZEOF_INT < SIZEOF_LONG
static VALUE numeric_spec_rb_num2uint(VALUE self, VALUE num) {
  return ULONG2NUM(rb_num2uint(num));
}
#endif

static VALUE numeric_spec_rb_num2ulong(VALUE self, VALUE num) {
  return ULONG2NUM(rb_num2ulong(num));
}

static VALUE numeric_spec_rb_num_zerodiv(VALUE self) {
  rb_num_zerodiv();
  return Qnil;
}

static VALUE numeric_spec_rb_cmpint(VALUE self, VALUE val, VALUE b) {
  return INT2FIX(rb_cmpint(val, val, b));
}

static VALUE numeric_spec_rb_num_coerce_bin(VALUE self, VALUE x, VALUE y, VALUE op) {
  return rb_num_coerce_bin(x, y, SYM2ID(op));
}

static VALUE numeric_spec_rb_num_coerce_cmp(VALUE self, VALUE x, VALUE y, VALUE op) {
  return rb_num_coerce_cmp(x, y, SYM2ID(op));
}

static VALUE numeric_spec_rb_num_coerce_relop(VALUE self, VALUE x, VALUE y, VALUE op) {
  return rb_num_coerce_relop(x, y, SYM2ID(op));
}

static VALUE numeric_spec_rb_absint_singlebit_p(VALUE self, VALUE num) {
  return INT2FIX(rb_absint_singlebit_p(num));
}

void Init_numeric_spec(void) {
  VALUE cls = rb_define_class("CApiNumericSpecs", rb_cObject);
  rb_define_method(cls, "size_of_VALUE", numeric_spec_size_of_VALUE, 0);
  rb_define_method(cls, "size_of_long_long", numeric_spec_size_of_long_long, 0);
  rb_define_method(cls, "NUM2CHR", numeric_spec_NUM2CHR, 1);
  rb_define_method(cls, "rb_int2inum_14", numeric_spec_rb_int2inum_14, 0);
  rb_define_method(cls, "rb_uint2inum_14", numeric_spec_rb_uint2inum_14, 0);
  rb_define_method(cls, "rb_uint2inum_n14", numeric_spec_rb_uint2inum_n14, 0);
  rb_define_method(cls, "rb_Integer", numeric_spec_rb_Integer, 1);
  rb_define_method(cls, "rb_ll2inum_14", numeric_spec_rb_ll2inum_14, 0);
  rb_define_method(cls, "rb_ull2inum_14", numeric_spec_rb_ull2inum_14, 0);
  rb_define_method(cls, "rb_ull2inum_n14", numeric_spec_rb_ull2inum_n14, 0);
  rb_define_method(cls, "rb_num2dbl", numeric_spec_rb_num2dbl, 1);
#if SIZEOF_INT < SIZEOF_LONG
  rb_define_method(cls, "rb_num2int", numeric_spec_rb_num2int, 1);
#endif

  rb_define_method(cls, "rb_num2long", numeric_spec_rb_num2long, 1);
  rb_define_method(cls, "rb_int2num", numeric_spec_rb_int2num, 1);
#if SIZEOF_INT < SIZEOF_LONG
  rb_define_method(cls, "rb_num2uint", numeric_spec_rb_num2uint, 1);
#endif

  rb_define_method(cls, "rb_num2ulong", numeric_spec_rb_num2ulong, 1);
  rb_define_method(cls, "rb_num_zerodiv", numeric_spec_rb_num_zerodiv, 0);
  rb_define_method(cls, "rb_cmpint", numeric_spec_rb_cmpint, 2);
  rb_define_method(cls, "rb_num_coerce_bin", numeric_spec_rb_num_coerce_bin, 3);
  rb_define_method(cls, "rb_num_coerce_cmp", numeric_spec_rb_num_coerce_cmp, 3);
  rb_define_method(cls, "rb_num_coerce_relop", numeric_spec_rb_num_coerce_relop, 3);
rb_define_method(cls, "rb_absint_singlebit_p", numeric_spec_rb_absint_singlebit_p, 1);
}

#ifdef __cplusplus
}
#endif
