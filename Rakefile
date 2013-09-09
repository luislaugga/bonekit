require 'rubygems'
require 'rake'
require 'rake/extensiontask'
require 'bundler'
require 'fileutils'

Bundler::GemHelper.install_tasks

Rake::ExtensionTask.new('bonekit') do |extension|
  extension.lib_dir = 'lib/bonekit'
end

task :default => :build
