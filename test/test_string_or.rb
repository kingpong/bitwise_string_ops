#!/usr/bin/env ruby
require 'test/unit'
require 'test/test_helper'
require 'bitwise_string_ops'

class TestStringOr < Test::Unit::TestCase

  def test_empty
    assert_equal "" | "", ""
  end
  
  def test_single
    assert_equal "0" | "1", "1"
    assert_equal "a" | "A", "a"
  end

  def test_multiple
    assert_equal "01" | "10", "11"
    assert_equal "aB" | "Ab", "ab"
  end
  
  def test_overflow
    assert_equal "111" | "00", "111"
    assert_equal "00" | "111", "111"
  end
  
  def test_non_string
    assert_equal "1"  | 1, "1"  | "1"
    assert_equal "10" | 1, "10" | "1"
  end
  
  def test_truth_table
    assert_equal "0" | "0", "0"
    assert_equal "0" | "1", "1"
    assert_equal "1" | "0", "1"
    assert_equal "1" | "1", "1"
  end
  
  # superficial test for perl equivalency
  def test_perldoc
    assert_equal "JA" | "  ph\n", "japh\n"
  end

end
