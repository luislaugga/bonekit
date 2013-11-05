require 'bundler'
require 'rake'
require 'rake/extensiontask'
require 'rake/testtask'
require 'rspec/core'
require 'rspec/core/rake_task'
require 'yard'

require 'fileutils'

spec = Gem::Specification.load('bonekit.gemspec')

Bundler::GemHelper.install_tasks

Rake::ExtensionTask.new('bonekit', spec) do |ext|
  ext.lib_dir = 'lib/bonekit'
end

Gem::PackageTask.new(spec) do |pkg|
end

task :default => :build

RSpec::Core::RakeTask.new(:spec) do |t|
  t.rspec_opts = ["-c", "-f progress"]
  t.rspec_opts << "-Ilib"
  t.pattern = 'spec/**/*_spec.rb'
  t.verbose = true
end

task :spec => :compile

Rake::TestTask.new(:test) do |t|
  t.libs = ["lib", "test"]
  t.warning = true
  t.verbose = true
  t.test_files = FileList['test/unit/*_test.rb']
end

task :test => :compile

YARD::Rake::YardocTask.new(:doc) do |t|
  t.files   = ['lib/**/*.rb','ext/**/*.c']
  t.options = ['-o docs/']
  t.options << '--debug' << '--verbose' if $trace
end

desc "Update bonekit-c dependency"
task :deps do
  system("cp -rf deps/bonekit-c/src/*.h ext/bonekit/")
  system("cp -rf deps/bonekit-c/src/*.c ext/bonekit/")
end
