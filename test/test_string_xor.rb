#!/usr/bin/env ruby
require 'test/unit'
require 'test/test_helper'
require 'bitwise_string_ops'

class TestStringXor < Test::Unit::TestCase

  def test_empty
    assert_equal "" ^ "", ""
  end
  
  def test_single
    assert_equal "0" ^ "1", "\001"
    assert_equal "a" ^ "A", " "
  end

  def test_multiple
    assert_equal "01" ^ "10", "\001\001"
    assert_equal "aB" ^ "Ab", "  "
  end
  
  def test_reversible
    orig = "abc"
    mask = "def"
    assert_not_equal orig ^ mask, orig
    assert_equal( (orig ^ mask) ^ mask, orig)
  end
  
  def test_overflow
    assert_equal "111" ^ "00",  "\001\0011"
    assert_equal "00"  ^ "111", "\001\0011"
  end
  
  def test_perldoc
    assert_equal "j p \n" ^ " a h", "JAPH\n"
  end

end
