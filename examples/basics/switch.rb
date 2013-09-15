require 'bonekit'

switchPin = Pin.new 30
ledPin = Pin.new 31, Output

loop do
  ledPin.value = switchPin.value 
  sleep 0.01
end

