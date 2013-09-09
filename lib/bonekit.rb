base_path = File.expand_path(File.dirname(__FILE__))
require File.join(base_path, 'bonekit', 'version')
begin
  m = /(\d+.\d+)/.match(RUBY_VERSION)
  ver = m[1]
  require File.join(base_path, 'bonekit', ver, 'bonekit')
rescue LoadError
  require File.join(base_path, 'bonekit', 'bonekit')
end
