#!/usr/bin/env ruby
require 'test/unit'
require 'bitwise_string_ops'

class TestStringAnd < Test::Unit::TestCase

  def test_perldoc
    assert_equal "japh\nJunk" & "_____", "JAPH\n"
  end

end
