require 'bonekit'

pin = Pin.new 31, Output

loop do
  pin.value = High
  sleep 1.0
  pin.value = Low
  sleep 1.0
end
