#
# bitwise_string_ops.rb
#
# BitwiseStringOps provides bitwise operators for the String class that
# mimic Perl's bitwise string operators.
# See http://perldoc.perl.org/perlop.html#Bitwise-String-Operators.
#
# Author:: Philip Garrett
# Copyright:: Copyright (c) 2009 Philip Garrett.
# License:: MIT License (http://www.opensource.org/licenses/mit-license.php)
#
#
require 'bitwise_string_ops.so'
class String
  include BitwiseStringOps
  alias :| :string_bitwise_or
  alias :^ :string_bitwise_xor
  alias :& :string_bitwise_and
  alias :~ :string_bitwise_not
end
