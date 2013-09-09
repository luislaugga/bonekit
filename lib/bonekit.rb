here = File.expand_path(File.dirname(__FILE__))
require File.join(here, 'bonekit', 'version')
begin
  m = /(\d+.\d+)/.match(RUBY_VERSION)
  ver = m[1]
  require File.join(here, 'bonekit', ver, 'bonekit')
rescue LoadError
  require File.join(here, 'bonekit', 'bonekit')
end
