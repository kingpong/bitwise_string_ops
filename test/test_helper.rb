
HERE = File.dirname(__FILE__)
%w(ext lib bin test).each do |dir|
  $LOAD_PATH.unshift "#{HERE}/../#{dir}"
end
