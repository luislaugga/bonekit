# Fading
#
# This example shows how to fade an LED using the Pin analog_value= method.
#
# The circuit:
# * LED with 180 ohm resistor attached from pin P9_42 to ground.
#
#

require 'bonekit'

led = Pin.new P9_42 # LED connected to a pin that supports PWM

fade_value = 0.0

loop do
  while fade_value <= 1.0 do # fade in from min to max in increments of 1%
    led.analog_value = fade_value # change the analog value
    fade_value += 0.01 # increment
    sleep(0.03) # wait for 30 milliseconds to see the fading effect   
  end
  
  while fade_value >= 0.0 do # fade out from max to min in increments of 1%
    led.analog_value = fade_value # change the analog value
    fade_value -= 0.01 # decrement
    sleep(0.03) # wait for 30 milliseconds to see the dimming effect  
  end
end