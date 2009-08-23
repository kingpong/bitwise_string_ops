#!/usr/bin/env ruby
require 'test/unit'
require 'test/test_helper'
require 'bitwise_string_ops'

class TestStringNot < Test::Unit::TestCase

  def test_empty
    assert_equal "" & "", ""
  end
  
  def test_single
    assert_equal ~"1", "\316"
    assert_equal ~"a", "\236"
  end

  def test_multiple
    assert_equal ~"01", "\317\316"
    assert_equal ~"aB", "\236\275"
  end

  def test_perldoc
    assert_equal ~"japh", "\225\236\217\227"
  end

end
