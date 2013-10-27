require 'test_helper'

class I2cTest < Test::Unit::TestCase
  
  def setup
  end
  
  def teardown
  end
  
  def test_initialization
    assert_not_nil(I2c.new 0x1e)
    assert_nil(I2c.new 0x00)
  end
  
  def test_read
    i2c = I2c.new 0x1e
    
    assert_not_nil(i2c)
    assert_not_nil(i2c.read(1))
  end
  
  def test_write
    i2c = I2c.new 0x1e
    
    assert_not_nil(i2c)
    assert_equal(1, i2c.write([0x00]))
  end
  
end