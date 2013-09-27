# Potentiometer
#
# This example shows how to control the brightness of an LED using a potentiometer.
#
# The circuit:
# * LED with 180 ohm resistor attached from pin P9_42 to DGND.
# * Potentiometer attached to pin P9_39, VDD_ADC and GNDA_ADC.
#

require 'bonekit'

led = Pin.new P9_42 # LED connected to a pin that supports PWM
pot = Pin.new P9_39 # Potentiometer connected to an ADC pin

loop do
  led.analog_value = pot.analog_value
  sleep(0.01) # 100Hz refresh rate
end