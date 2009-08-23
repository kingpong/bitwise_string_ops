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

#include "ruby.h"
#include "bitwise_string_ops.h"

static ID ToString;
static VALUE to_s(VALUE o);

/* callback for module init */
void Init_bitwise_string_ops();

VALUE method_bit_or(VALUE self, VALUE other);
VALUE method_bit_xor(VALUE self, VALUE other);
VALUE method_bit_and(VALUE self, VALUE other);
VALUE method_bit_not(VALUE self);

void Init_bitwise_string_ops()
{
    ToString = rb_intern("to_s");
    rb_define_method(rb_cString, "|", method_bit_or,  1);
    rb_define_method(rb_cString, "^", method_bit_xor, 1);
    rb_define_method(rb_cString, "&", method_bit_and, 1);
    rb_define_method(rb_cString, "~", method_bit_not, 0);
}

static VALUE to_s(VALUE o)
{
    return rb_obj_is_kind_of(o,rb_cString)
        ? o : rb_funcall(o, ToString, 0);
}

/*
 * call-seq:
 *  |(other)
 *
 * Performs a byte-by-byte bitwise OR on +self+ (a String) and +other+
 * (anything that responds to +to_s+) and returns the result.  If one
 * operand is longer than the other, the effect is as if the shorter
 * operand were padded with zero bits on the right.  The result is as
 * long as the <b>longer</b> operand.
 *
 * Example:
 *
 *   "RU" | "  by"     # "ruby"
 *   #
 *   #   01010010 01010101                    # "RU"
 *   # | 00100000 00100000 01100010 01111001  # "  by"
 *   #   ======== ======== ======== ========
 *   #   01110010 01110101 01100010 01111001  # "ruby"
 *
 *
 */
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

/*
 * call-seq:
 *  ^(other)
 *
 * Performs a byte-by-byte bitwise XOR on +self+ (a String) and +other+
 * (anything that responds to +to_s+) and returns the result.  If one
 * operand is longer than the other, the effect is as if the shorter
 * operand were padded with zero bits on the right.  The result is as
 * long as the <b>longer</b> operand.
 *
 * Example:
 *
 *   "%:--!" ^ "woot"  # "RUBY!"
 *   #
 *   #   00100101 00111010 00101101 00101101 00100001  # "%:--!"
 *   # ^ 01110111 01101111 01101111 01110100           # "woot"
 *   #   ======== ======== ======== ========
 *   #   01010010 01010101 01000010 01011001 00100001  # "RUBY!"
 *
 */
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

/*
 * call-seq:
 *  &(other)
 *
 * Performs a byte-by-byte bitwise AND on +self+ (a String) and +other+
 * (anything that responds to +to_s+) and returns the result.  If one
 * operand is longer than the other, the effect is as if the longer
 * operand were truncated to the length of the shorter.  The result is
 * as long as the <b>shorter</b> operand.
 *
 * Example:
 *
 *   "ruby!" & '____'  # "ruby"
 *
 *   #   01110010 01110101 01100010 01111001 00100001  # "ruby!"
 *   # & 01011111 01011111 01011111 01011111           # "____"
 *   #   ======== ======== ======== ========
 *   #   01110010 01110101 01100010 01111001           # "ruby"
 *
 */
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

/*
 * call-seq:
 *  ~()
 *
 * Performs a byte-by-byte bitwise NOT on +self+ (a String) * and returns the result.
 *
 * Example:
 *
 *   ~"ruby" # "\215\212\235\206"
 *
 *   # ~ 01110010 01110101 01100010 01111001 # "ruby"
 *   #   ======== ======== ======== ========
 *   #   10001101 10001010 10011101 10000110 # "\215\212\235\206"
 *
 */
VALUE method_bit_not(VALUE self)
{
    VALUE str = StringValue(self);
    VALUE dest = rb_str_new(NULL,
                            string_bitwise_not_result_len(RSTRING(str)->len));
    string_bitwise_not(RSTRING(str)->ptr, RSTRING(str)->len,
                       RSTRING(dest)->ptr);
    return dest;
}
