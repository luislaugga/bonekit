# Device - Simple test of using HMC5883L I2C interface
#
# Connections:
# VCC to pin P9-4 (VDD_3V3)
# GND to pin P9-2 (DGND)
# SCL to P9_19 (I2C2_SCL)
# SDA to P9_20 (I2C2_SDA)
# 

require 'bonekit'

DeviceAddress = 0x1e

ModeRegister = 0x02
ReadRegister = 0x03
ModeContinuous = 0x00

device = I2c.new DeviceAddress

device.write([ModeRegister, ModeContinuous])

loop do
  device.write([ReadRegister])
  raw = device.read(6)
  x = (raw[0] << 8 | raw[1])
  z = (raw[2] << 8 | raw[3])
  y = (raw[4] << 8 | raw[5])
  axis = [x,y,z]
  puts "axis #{axis}"
  
  sleep(1)
end
