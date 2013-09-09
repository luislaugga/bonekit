require 'rubygems'
require 'rake'
require 'rake/extensiontask'
require 'bundler'

Rake::ExtensionTask.new("bonekit") do |extension|
  extension.lib_dir = "lib/bonekit"
end

task :chmod do
  File.chmod(0775, 'lib/bonekit/bonekit.so')
end
task :build => [:clean, :compile, :chmod]

Bundler::GemHelper.install_tasks

task :default => :build
