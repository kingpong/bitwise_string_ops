/*
 * bitwise_string_ops.c
 *
 * Copyright (c) 2009 Philip Garrett.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

// Include the Ruby headers and goodies
#include "ruby.h"
#include "bitwise_string_ops.h"

// Defining a space for information and references about the module to be stored internally
VALUE BitwiseStringOps = Qnil;
static ID ToString;

// Prototype for the initialization method - Ruby calls this, not you
void Init_bitwise_string_ops();

// Prototypes for our methods
VALUE method_bit_or(VALUE self, VALUE other);
VALUE method_bit_xor(VALUE self, VALUE other);
VALUE method_bit_and(VALUE self, VALUE other);
VALUE method_bit_not(VALUE self);

static VALUE to_s(VALUE o);

// The initialization method for this module
void Init_bitwise_string_ops()
{
    BitwiseStringOps = rb_define_module("BitwiseStringOps");
	ToString = rb_intern("to_s");
    rb_define_method(BitwiseStringOps, "|", method_bit_or,  1);
    rb_define_method(BitwiseStringOps, "^", method_bit_xor, 1);
    rb_define_method(BitwiseStringOps, "&", method_bit_and, 1);
    rb_define_method(BitwiseStringOps, "~", method_bit_not, 0);
}

static VALUE to_s(VALUE o)
{
	return rb_obj_is_kind_of(o,rb_cString)
		? o : rb_funcall(o, ToString, 0);
}

VALUE method_bit_or(VALUE self, VALUE other)
{
	VALUE left, right, right_s, dest;
	left = StringValue(self);
	right_s = to_s(other);
	right = StringValue(right_s);
    dest = rb_str_new(NULL, string_bitwise_or_result_len(RSTRING(left)->len,
                                                         RSTRING(right)->len));
    string_bitwise_or(RSTRING(left)->ptr, RSTRING(left)->len,
                      RSTRING(right)->ptr, RSTRING(right)->len,
                      RSTRING(dest)->ptr);
    return dest;
}

VALUE method_bit_xor(VALUE self, VALUE other)
{
	VALUE left, right, right_s, dest;
	left = StringValue(self);
	right_s = to_s(other);
	right = StringValue(right_s);
    dest = rb_str_new(NULL, string_bitwise_xor_result_len(RSTRING(left)->len,
                                                          RSTRING(right)->len));
    string_bitwise_xor(RSTRING(left)->ptr, RSTRING(left)->len,
                       RSTRING(right)->ptr, RSTRING(right)->len,
                       RSTRING(dest)->ptr);
    return dest;
}

VALUE method_bit_and(VALUE self, VALUE other)
{
	VALUE left, right, right_s, dest;
	left = StringValue(self);
	right_s = to_s(other);
	right = StringValue(right_s);
    dest = rb_str_new(NULL, string_bitwise_and_result_len(RSTRING(left)->len,
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
