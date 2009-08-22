# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{bitwise_string_ops}
  s.version = "0.1.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.2") if s.respond_to? :required_rubygems_version=
  s.authors = ["Philip Garrett"]
  s.date = %q{2009-08-22}
  s.description = %q{Bitwise operations for Ruby strings}
  s.email = %q{philip@pastemagazine.com}
  s.extensions = ["ext/extconf.rb"]
  s.extra_rdoc_files = ["CHANGELOG", "ext/bitwise.c", "ext/bitwise_string_ops.c", "ext/bitwise_string_ops.h", "ext/extconf.rb", "lib/bitwise_string_ops.rb", "README.rdoc"]
  s.files = ["bitwise_string_ops.gemspec", "CHANGELOG", "ext/bitwise.c", "ext/bitwise_string_ops.c", "ext/bitwise_string_ops.h", "ext/extconf.rb", "init.rb", "lib/bitwise_string_ops.rb", "Manifest", "Rakefile", "README.rdoc", "setup.rb", "test/test.rb", "test/test_helper.rb", "test/test_string_and.rb", "test/test_string_not.rb", "test/test_string_or.rb", "test/test_string_xor.rb"]
  s.homepage = %q{http://github.com/kingpong/bitwise_string_ops}
  s.rdoc_options = ["--line-numbers", "--inline-source", "--title", "Bitwise_string_ops", "--main", "README.rdoc"]
  s.require_paths = ["lib", "ext"]
  s.rubyforge_project = %q{bitwise_string_ops}
  s.rubygems_version = %q{1.3.3}
  s.summary = %q{Bitwise operations for Ruby strings}
  s.test_files = ["test/test_helper.rb", "test/test_string_and.rb", "test/test_string_not.rb", "test/test_string_or.rb", "test/test_string_xor.rb"]

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 3

    if Gem::Version.new(Gem::RubyGemsVersion) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
