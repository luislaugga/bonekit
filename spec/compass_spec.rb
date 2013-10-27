require 'spec_helper'

describe HMC5883L do
  
  describe "heading" do
    
    let :compass do
      HMC5883L.new
    end
    
    context "when default" do
      it "returns float in degrees" do
        compass.heading.class.should eq(Float)
      end
    end
  end
end