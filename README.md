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

## Example

This example turns the LED on when a push button is pressed. The pin _P9-11_ has a 10K pull-up resistor connected to GND. 

```ruby
require 'bonekit'

switchPin = Pin.new P9_11
ledPin = Pin.new P9_13, Output

loop do
  ledPin.value = switchPin.value 
  sleep 0.01
end
```

## Reference

__Digital Input/Output__

```ruby
pin = Pin.new P9_11 # Input pin by default
pin = Pin.new P9_13, Output # Output pin

value = pin.value # Read value
pin.value = value # Write value

pin.mode = Input # Set mode
```

__Analog Input__

```ruby
analog_pin = Pin.new P9_39 # Analog pin AIN0

analog_value = analog_pin.analog_value # Read analog value (0.0 to 1.0)
```

__Devices (ICs)__

```ruby
compass = HMC5883L.new
heading = compass.heading # degrees
```

## Roadmap

* Digital Input/Output (implemented)
* Analog Input (implemented)
* Analog Output (planned)
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

