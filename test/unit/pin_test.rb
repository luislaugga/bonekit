require 'test_helper'

class PinTest < Test::Unit::TestCase
  
  def setup
    @pin = Pin.new 30
  end
  
  def teardown
  end
  
  def test_mode
    @pin.mode = Input
    assert_equal(Input, @pin.mode)
    assert_equal("in", File.open('/sys/class/gpio/gpio30/direction').read)
    
    @pin.mode = Output
    assert_equal(Output, @pin.mode)
    assert_equal("out", File.open('/sys/class/gpio/gpio30/direction').read)
  end
  
  def test_value
    @pin.value = Low
    assert_equal(Low, @pin.value)
    assert_equal(0, File.open('/sys/class/gpio/gpio30/value').read)

    @pin.value = High
    assert_equal(High, @pin.value)
    assert_equal(1, File.open('/sys/class/gpio/gpio30/value').read)
  end
  
end