#!/usr/bin/env ruby

$: << File.join(File.dirname(__FILE__),"..","lib")
$: << File.dirname(__FILE__)

$stderr.puts $:.to_yaml

require 'test/unit'
require 'test_string_or'
require 'test_string_xor'
require 'test_string_and'
require 'test_string_not'
