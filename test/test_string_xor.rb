#!/usr/bin/env ruby
require 'test/unit'
require 'bitwise_string_ops'

class TestStringXor < Test::Unit::TestCase

  def test_perldoc
    assert_equal "j p \n" ^ " a h", "JAPH\n"
  end

end
