require 'test_helper'

class PinAdcTest < Test::Unit::TestCase
  
  def setup
    @pin = Pin.new P9_39 # AIN 0
  end
  
  def teardown
  end
  
  def test_analog_value
    assert((@pin.analog_value - (File.open('/sys/bus/iio/devices/iio:device0/in_voltage0_raw').read.chomp.to_f/4095.0)).abs < 0.001)
  end
  
end