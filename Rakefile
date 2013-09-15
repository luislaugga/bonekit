require 'bundler'
require 'rake'
require 'rake/extensiontask'
require 'rake/testtask'
require 'rspec/core'
require 'rspec/core/rake_task'
require 'yard'

require 'fileutils'

Bundler::GemHelper.install_tasks

Rake::ExtensionTask.new('bonekit') do |extension|
  extension.lib_dir = 'lib/bonekit'
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

desc 'Generate YARD document'
YARD::Rake::YardocTask.new(:doc) do |t|
  t.files   = ['lib/**/*.rb','ext/**/*.c']
  t.options = ['-o docs/']
  t.options << '--debug' << '--verbose' if $trace
end