# Photo resistor - Simple test of the functionality of the photo resistor
#
# Connect the photoresistor one leg to pin P9-39 and other leg to pin P9-32 (VDD_ADC)
# Connect a resistor (around 10k is a good value, higher values gives higher readings) 
# from pin P9-39 to pin P9-34 (GND_ADC).
#
# Circuit:
# 
#               Photo Resistor     10K
#  +1.8 (P9-32) o---/\/\/----.----/\/\/---o GND_ADC (P9-34)
#                            |
#  AIN0 (P9-39) o------------+
# 

require 'bonekit'

photo_resistor = Pin.new P9_39 # AIN0

light_readings = [0.0]
light_threshold = 0.05 # Log all changes above threshold

loop do
  light_reading = photo_resistor.analog_value
  
  if (light_reading - light_readings.last).abs > light_threshold
    light_readings << light_reading
    puts "Light is at #{(light_reading*100.0).round}%"
  end
  
  sleep(0.1)
end
