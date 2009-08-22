#!/usr/bin/env ruby

$: << File.join(File.dirname(__FILE__),"..")
$: << File.dirname(__FILE__)

require 'test/unit'
require 'test_string_or'
require 'test_string_xor'
require 'test_string_and'
require 'test_string_not'
