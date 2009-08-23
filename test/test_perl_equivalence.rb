#!/usr/bin/env ruby
require 'test/unit'
require 'test/test_helper'
require 'bitwise_string_ops'

class TestPerlEquivalence < Test::Unit::TestCase

  PATH_SEP  = RUBY_PLATFORM =~ /mswin/i ? ";" : ":"
  GENERATOR = File.join(File.dirname(__FILE__),"testcases.pl")

  def test_perl_equivalence
    return unless perl = find_perl
    pipe_reader(perl, GENERATOR) do |pipe|
      while op = read_string(pipe)
        case op
        when "|"
          result, left, right = read_strings(pipe,3)
          assert_equal left | right, result
        when "^"
          result, left, right = read_strings(pipe,3)
          assert_equal left ^ right, result
        when "&"
          result, left, right = read_strings(pipe,3)
          assert_equal left & right, result
        when "~"
          result, operand = read_strings(pipe,2)
          assert_equal ~operand, result
        end
      end
    end
  end
  
  private
  
  def find_perl
    ENV["PATH"].split(PATH_SEP).
      map  {|path| File.join(path,"perl") }.
      find {|perl| File.executable?(perl) }
  end

  # Runs a command and yields an IO object opened for reading from the command.
  # Does *NOT* do any shell expansion (that's the point).
  # +args+ should be [program,arg1,...]
  def pipe_reader(*args)
    # avoid shell expansion using fork/exec
    reader, writer = IO.pipe
    pid = fork
    if pid
      writer.close
      yield(reader)
      Process.waitpid(pid)
    else
      begin
        reader.close
        STDIN.reopen("/dev/null")
        STDOUT.reopen(writer)
        exec(*args)
      rescue => e
        # prevent child from jumping out of this scope and continuing main program
        STDERR.puts(e.to_s)
      end
      exit! # will only reach here if exec() failed
    end
  end
    
  def read_string(io)
    length = io.read(4).unpack("N").first
    io.read(length)
  rescue => e
    io.eof? ? nil : raise(e)
  end

  def read_strings(io,n)
    ret = []
    n.times { ret << read_string(io) }
    ret
  end

end
