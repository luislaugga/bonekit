require 'spec_helper'

describe Pin do
  
  describe "mode" do
    
    let :pin do
      Pin.new P9_13
    end
    
    context "when default" do
      it "returns Input" do
        pin.mode.should eq(Input)
      end
    end
    
    context "when set to Output" do
      before(:each) { pin.mode = Output }
      it "returns Output" do
        pin.mode.should eq(Output)
      end
    end
    
    context "when set to Input" do
      before(:each) { pin.mode = Input }
      it "returns Input" do
        pin.mode.should eq(Input)
      end
    end
  end
  
  describe "value" do
    
    let :pin do
      Pin.new P9_11
    end
    
    context "when default" do
      it "returns 0" do
        pin.value.should eq(0)
      end
    end
    
    context "when default and mode is Output" do
      before(:each) { pin.mode = Output }
      it "returns 0" do
        pin.value.should eq(0)
      end
    end
    
    context "when set to 1 and mode is Output" do
      before(:each) { 
        pin.mode = Output 
        pin.value = 1
      }
      it "returns 1" do
        pin.value.should eq(1)
      end
    end
  end
  
  describe "analog_value" do
    
    let :pin do
      Pin.new P9_39 # AIN
    end
    
    it "returns value between 0.0 and 1.0" do
      pin.analog_value.should be >= 0.0
      pin.analog_value.should be <= 1.0
    end
  end
  
  describe "analog_value=" do
    
    let :pin do
      Pin.new P9_42 # PWM
    end
    
    context "when default" do
      it "returns 0.0" do
        pin.analog_value.should eq(0.0)
      end
    end
    
    context "when set to 1.0" do
      before(:each) { 
        pin.analog_value = 1.0
      }
      it "returns 1.0" do
        pin.analog_value.should eq(1.0)
      end
    end
  end
end