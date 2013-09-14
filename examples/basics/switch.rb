require 'bonekit'

switchPin = Pin.new 30
switchPin.mode = 0

ledPin = Pin.new 31
ledPin.mode = 1

loop do
 if switchPin.value == 0 # switch is pressed
  ledPin.value = 1
 else
  ledPin.value = 0
 end
 sleep 0.01
end

