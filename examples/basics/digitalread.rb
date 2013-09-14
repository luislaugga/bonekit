require 'bonekit'

pin = Pin.new 30

loop do
 value = pin.value
 puts "Value: #{value}"
 sleep(0.1)
end
