require 'bonekit'

pin = Pin.new P9_39 # AIN0

loop do
 analog_value = pin.analog_value
 puts "Analog Value: #{analog_value}"
 sleep(0.1)
end
