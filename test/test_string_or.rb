#!/usr/bin/env ruby
require 'test/unit'
require 'bitwise_string_ops'

class TestStringOr < Test::Unit::TestCase

  def test_perldoc
    assert_equal "JA" | "  ph\n", "japh\n"
  end

end
