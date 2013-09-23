require 'bonekit'

pin = Pin.new P9_13, Output

loop do
  pin.value = High
  sleep 1.0
  pin.value = Low
  sleep 1.0
end
