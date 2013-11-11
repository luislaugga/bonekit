require 'spec_helper'

describe ADXL345 do
  
  describe "raw_acceleration" do
    
    let :accelerometer do
      ADXL345.new
    end
    
    context "when default" do
      it "returns raw acceleration vector with 3 elements" do
        accelerometer.raw_acceleration.class.should eq(Array)
        accelerometer.raw_acceleration.length.should eq(3)
      end
    end
  end
end