require 'rubygems'
require 'rake'
require 'echoe'

project = "bitwise_string_ops"
version = "0.1.2"

Echoe.new(project, version) do |p|
  p.description = "Bitwise operations for Ruby strings"
  p.summary = "#{project} #{version}"
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
