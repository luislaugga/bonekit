# BoneKit

_BoneKit is a physical interface toolkit for the BeagleBone._

BoneKit is a ruby library that facilitates the creation of physical interaction experiments using the BeagleBone. It gives access to low-level hardware features (PWM, SPI, I2C, ADC) and includes support for some ICs (TLC5940, ADLX335, HMC5883L).

## Getting Started

```ruby
require 'bonekit'
compass = HMC5883L.new
heading = compass.heading
```

Use RubyGems to install:

```
gem install bonekit
```

or build and install:

```
bundle
rake
gem install --local pkg/bonekit
```

## Reference

__Pin digital Input/Output__

* digitalRead()
* digitalWrite()

__Pin analog Input__

__Pin PWM (analog) Output__

__Serial Communication__

__I2C__

__SPI__

__Devices (ICs)__

* HMC5883L

