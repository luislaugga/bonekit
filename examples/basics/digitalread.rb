require 'bonekit'

pin = Pin.new P9_11

loop do
 value = pin.value
 puts "Value: #{value}"
 sleep(0.1)
end
