#!/usr/bin/env ruby
require 'test/unit'
require 'test/test_helper'
require 'bitwise_string_ops'

class TestStringNot < Test::Unit::TestCase

  def test_perldoc
    assert_equal ~"japh", "\225\236\217\227"
  end

end
