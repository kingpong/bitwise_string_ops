
// Include the Ruby headers and goodies
#include "ruby.h"
#include "bitwise_string_ops.h"

// Defining a space for information and references about the module to be stored internally
VALUE BitwiseStringOps = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_bitwise_string_ops();

// Prototypes for our methods
VALUE method_bit_or(VALUE self, VALUE other);
VALUE method_bit_xor(VALUE self, VALUE other);
VALUE method_bit_and(VALUE self, VALUE other);
VALUE method_bit_not(VALUE self);

// The initialization method for this module
void Init_bitwise_string_ops()
{
    BitwiseStringOps = rb_define_module("BitwiseStringOps");
    rb_define_method(BitwiseStringOps, "bit_or",  method_bit_or,  1);
    rb_define_method(BitwiseStringOps, "bit_xor", method_bit_xor, 1);
    rb_define_method(BitwiseStringOps, "bit_and", method_bit_and, 1);
    rb_define_method(BitwiseStringOps, "bit_not", method_bit_not, 0);
}

VALUE method_bit_or(VALUE self, VALUE other)
{
    VALUE left = StringValue(self), right = StringValue(other);
    VALUE dest = rb_str_new(NULL,
                            string_bitwise_or_result_len(RSTRING(left)->len,
                                                         RSTRING(right)->len));
    string_bitwise_or(RSTRING(left)->ptr, RSTRING(left)->len,
                      RSTRING(right)->ptr, RSTRING(right)->len,
                      RSTRING(dest)->ptr);
    return dest;
}

VALUE method_bit_xor(VALUE self, VALUE other)
{
    VALUE left = StringValue(self), right = StringValue(other);
    VALUE dest = rb_str_new(NULL,
                            string_bitwise_xor_result_len(RSTRING(left)->len,
                                                          RSTRING(right)->len));
    string_bitwise_xor(RSTRING(left)->ptr, RSTRING(left)->len,
                       RSTRING(right)->ptr, RSTRING(right)->len,
                       RSTRING(dest)->ptr);
    return dest;
}

VALUE method_bit_and(VALUE self, VALUE other)
{
    VALUE left = StringValue(self), right = StringValue(other);
    VALUE dest = rb_str_new(NULL,
                            string_bitwise_and_result_len(RSTRING(left)->len,
                                                          RSTRING(right)->len));
    string_bitwise_and(RSTRING(left)->ptr, RSTRING(left)->len,
                       RSTRING(right)->ptr, RSTRING(right)->len,
                       RSTRING(dest)->ptr);
    return dest;
}

VALUE method_bit_not(VALUE self)
{
    VALUE str = StringValue(self);
    VALUE dest = rb_str_new(NULL,
                            string_bitwise_not_result_len(RSTRING(str)->len));
    string_bitwise_not(RSTRING(str)->ptr, RSTRING(str)->len,
                       RSTRING(dest)->ptr);
    return dest;
}
