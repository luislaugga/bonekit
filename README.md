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

__Pin Input/Output__

```ruby
pin = Pin.new 30 # gpio = 30, mode = Input
pin = Pin.new 30, Output # gpio = 30, mode = Output

value = pin.value # Read value
pin.value = value # Write value

pin.mode = Input # Set mode
```

__Devices (ICs)__

```ruby
compass = HMC5883L.new
heading = compass.heading # degrees
```

## Roadmap

* Digital Input/Output (in progress, with issues)
* Analog Input/Output (planned)
* Interrupts (planned)
* Serial Communication (planned)
* I2C (planned)
* SPI (planned)
* Devices:
  * HMC5883L (implemented, with issues)
  * ADXL345 (planned)
  * ITG-3200 (planned) 
  * TLC5940 (planned)
* Other:
  * Capacitive Sensor (planned)
  * Resistive Pressure Sensor (planned) 

