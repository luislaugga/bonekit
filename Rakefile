require 'bundler'
Bundler::GemHelper.install_tasks

spec = eval File.read("bonekit.gemspec")

if RUBY_PLATFORM =~ /java/
  require 'rake/javaextensiontask'

  Rake::JavaExtensionTask.new('msgpack', spec) do |ext|
    ext.ext_dir = 'ext/java'
  end

else
  require 'rake/extensiontask'

  Rake::ExtensionTask.new('bonekit', spec) do |ext|
    ext.cross_compile = true
    ext.lib_dir = File.join(*['lib', 'bonekit', ENV['FAT_DIR']].compact)
  end
end

task :default => :build
