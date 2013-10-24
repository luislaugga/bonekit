# Compass - Simple test of the functionality of the HMC5883L 3-Axis Digital Compass IC
#
# Connections:
# VCC to pin P9-4 (VDD_3V3)
# GND to pin P9-2 (DGND)
# SCL to P9_19 (I2C2_SCL)
# SDA to P9_20 (I2C2_SDA)
# 

require 'bonekit'

compass = HMC5883L.new

loop do
  puts "Heading: #{compass.heading} degrees"
  sleep(0.1)
end
