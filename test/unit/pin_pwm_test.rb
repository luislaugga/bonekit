require 'test_helper'

class PinPwmTest < Test::Unit::TestCase
  
  def setup
    @pin = Pin.new P9_42 # PWM
  end
  
  def teardown
  end
  
  def ocp_pwm_value
    File.open('/sys/devices/ocp.2/pwm_test_P9_42.14/duty').read.chomp.to_f/File.open('/sys/devices/ocp.2/pwm_test_P9_42.14/period').read.chomp.to_f 
  end
  
  def test_set_analog_value
    @pin.analog_value = 0.0
    assert_equal(@pin.analog_value, ocp_pwm_value)
    
    @pin.analog_value = 0.5
    assert_equal(@pin.analog_value, ocp_pwm_value)
    
    @pin.analog_value = 1.0
    assert_equal(@pin.analog_value, ocp_pwm_value)
    
    @pin.analog_value = -0.1
    assert_equal(0.0, @pin.analog_value)
    assert_equal(0.0, ocp_pwm_value)
    
    
    @pin.analog_value = 1.1
    assert_equal(1.0, @pin.analog_value)
    assert_equal(1.0, ocp_pwm_value)
  end
  
end