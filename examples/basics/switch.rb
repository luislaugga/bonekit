require 'bonekit'

switchPin = Pin.new 30, Input
ledPin = Pin.new 31, Output

loop do
 if switchPin.value == 0 # switch is pressed
  ledPin.value = 1
 else
  ledPin.value = 0
 end
 sleep 0.01
end

