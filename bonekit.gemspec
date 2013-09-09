$:.push File.expand_path("../lib", __FILE__)
require 'bonekit/version'

Gem::Specification.new do |s|
  s.name = "bonekit"
  s.version = BoneKit::VERSION
  s.summary = "BoneKit, a physical interaction toolkit for the beaglebone."
  s.description = %q{BoneKit is a beaglebone hardware interface library for ruby. It enables access to features such as PWM, I2C, ADC and common ICs.}
  s.author = "LAUGGA Luis"
  s.email = "dev@laugga.com"
  s.homepage = "http://laugga.com/bonekit"
  s.rubyforge_project = "bonekit"
  s.has_rdoc = false
  s.files = `git ls-files`.split("\n")
  s.test_files = `git ls-files -- {test,spec}/*`.split("\n")
  s.require_paths = ["lib"]
  s.extensions = ["ext/bonekit/extconf.rb"]

  s.add_development_dependency 'rake', ['~> 0.9.2']
end
