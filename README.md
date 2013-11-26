# BoneKit

_BoneKit is a physical computing toolkit for the BeagleBone._

BoneKit is a library for the beaglebone that provides easy access from ruby to low-level hardware features. It supports Digital Input/Output (GPIO), Analog Input (ADC), Pulse-Width Modulation (PWM) and I²C.

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
gem install --local pkg/bonekit-0.0.5.gem
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
pin = Pin.new P9_11 # Input mode pin by default
digital_value = pin.value # Read digital value (Low or High)

pin.mode = Output # Set mode to Output
pin.value = High # Write digital value (low or High)
```

__Analog Input/Output__

```ruby
pin = Pin.new P9_39 # Analog pin
analog_value = pin.analog_value # Read analog value (0.0 to 1.0)
```

```ruby
pin = Pin.new P9_42 # Pulse-Width Modulation pin
pin.analog_value = 0.3 # Write analog value (0.0 to 1.0)
```
__I2C__

```ruby
device = I2c.new address
device.read(1) # read 1 byte
device.write([0x03,0x00]) # write 2 bytes
```

__Devices (ICs)__

```ruby
compass = HMC5883L.new
heading = compass.heading # degrees
```

```ruby
accelerometer = ADXL345.new
raw_acceleration = compass.raw_acceleration # [x,y,z]
```

## Roadmap

* Digital Input/Output (implemented)
* Analog Input (implemented)
* Analog Output (implemented)
* I2C (implemented)
* SPI (planned)
* Interrupts (planned)
* Serial Communication (planned)
* Devices:
  * HMC5883L (support for heading in degrees)
  * ADXL345 (support for raw acceleration)
  * ITG-3200 (planned) 
  * TLC5940 (planned)
* Libraries:
  * Capacitive Sensor (planned)
  * Resistive Pressure Sensor (planned) 

## Development Notes

Build and install native gem:

```
rake native gem
gem install --local pkg/bonekit-0.0.5-arm-linux.gem
```  