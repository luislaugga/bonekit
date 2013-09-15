require 'spec_helper'

describe Pin do
  
  let :pin do
    Pin.new 30
  end
  
  describe "mode" do
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
end