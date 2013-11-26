$:.push File.expand_path("../lib", __FILE__)
require 'bonekit/version'

Gem::Specification.new do |s|
  s.platform    = Gem::Platform::RUBY
  s.name        = "bonekit"
  s.version     = BoneKit::VERSION
  s.summary     = "Physical computing toolkit for the beaglebone."
  s.description = %q{BoneKit is a physical computing library for the beaglebone. It provides easy access from ruby to hardware features such as: Digital I/O, Analog Read, Pulse-Width Modulation and I2C.}
  
  s.license = 'MIT'
  
  s.author   = "Luis Laugga"
  s.email    = "luis@laugga.com"
  s.homepage = "http://laugga.com/bonekit"
  
  s.files      = `git ls-files`.split("\n") - %w(.gitignore deps/bonekit-c)
  s.test_files = `git ls-files -- {test,spec}/*`.split("\n")
  
  s.require_paths = ["lib"]
  s.extensions    = ["ext/bonekit/extconf.rb"]

  s.add_development_dependency 'bundler',       '>= 1.0'
  s.add_development_dependency 'rake',          '>= 0.9.0'
  s.add_development_dependency 'rake-compiler', '>= 0.9.1'
  s.add_development_dependency 'rspec',          '>= 2.0.0'
  s.add_development_dependency 'yard',          '>= 0.8.0'
end

