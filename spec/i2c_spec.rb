require 'spec_helper'

describe I2c do
  
  describe "read" do
    
    let :i2c do
      I2c.new 0x1e
    end
    
    context "when default" do
      it "returns read bytes array" do
        pin.read(1).should be > 0
      end
    end
  end
  
  describe "write" do
    
    let :i2c do
      I2c.new 0x1e
    end
    
    context "when default" do
      it "returns number of write bytes" do
        pin.write([0x00]).should eq(1)
      end
    end
  end
end