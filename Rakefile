require 'rubygems'
require 'rake'
require 'echoe'

Echoe.new("bitwise_string_ops", "0.1.0") do |p|
  p.description = "Bitwise operations for Ruby strings"
  p.url = "http://github.com/kingpong/bitwise_string_ops"
  p.author = "Philip Garrett"
  p.email = "philip@pastemagazine.com"
  p.ignore_pattern = ["tmp/*","script/*","InstalledFiles"]
  p.development_dependencies = []
end

desc "Export changes from git into CHANGELOG"
task :changes do
  sh "git log > CHANGELOG"
end

task :manifest => :changes
task :gem => :changes
