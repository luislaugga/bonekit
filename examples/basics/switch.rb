require 'bonekit'

switchPin = Pin.new P9_11
ledPin = Pin.new P9_13, Output

loop do
  ledPin.value = switchPin.value 
  sleep 0.01
end

