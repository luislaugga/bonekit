# Accelerometer - Simple test of the functionality of the ADXL345 3-Axis Digital Accelerometer IC
#
# Connections:
# CS  to pin P9-4 (VDD_3V3)
# VCC to pin P9-4 (VDD_3V3)
# GND to pin P9-2 (DGND)
# SCL to P9_19 (I2C2_SCL)
# SDA to P9_20 (I2C2_SDA)
# 

require 'bonekit'

accelerometer = ADXL345.new

loop do
  raw_acceleration = accelerometer.raw_acceleration
  puts "Raw Acceleration:\nx #{raw_acceleration[0]}\ny #{raw_acceleration[1]}\nz #{raw_acceleration[2]}\n"
  sleep(0.1)
end
