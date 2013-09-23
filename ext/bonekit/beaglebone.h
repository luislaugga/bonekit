/*
 
 beaglebone.h
 BoneKit
 
 Copyright (cc) 2012 Luis Laugga.
 Some rights reserved, all wrongs deserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
*/

#ifndef BONEKIT_BEAGLEBONE_H__
#define BONEKIT_BEAGLEBONE_H__

#ifdef __cplusplus
extern "C" {
#endif

// Bit mask = GPIO (0-7), AIN (8-11), PWM (12-15)
#define USR0  0x3500 // USR0 { GPIO = 53}
#define USR1  0x3600 // USR1 { GPIO = 54}
#define USR2  0x3700 // USR2 { GPIO = 55}
#define USR3  0x3800 // USR3 { GPIO = 56}
#define P8_1  0x0000 // DGND
#define P8_2  0x0000 // DGND
#define P8_3  0x2600 // GPIO1_6 { GPIO = 38}
#define P8_4  0x2700 // GPIO1_7 { GPIO = 39}
#define P8_5  0x2200 // GPIO1_2 { GPIO = 34}
#define P8_6  0x2300 // GPIO1_3 { GPIO = 35}
#define P8_7  0x4200 // TIMER4 { GPIO = 66}
#define P8_8  0x4300 // TIMER7 { GPIO = 67}
#define P8_9  0x4500 // TIMER5 { GPIO = 69}
#define P8_10 0x4400 // TIMER6 { GPIO = 68}
#define P8_11 0x2d00 // GPIO1_13 { GPIO = 45}
#define P8_12 0x2c00 // GPIO1_12 { GPIO = 44}
#define P8_13 0x1704 // EHRPWM2B { GPIO = 23, PWM_MUX_MODE = 4 }
#define P8_14 0x1a00 // GPIO0_26 { GPIO = 26}
#define P8_15 0x2f00 // GPIO1_15 { GPIO = 47}
#define P8_16 0x2e00 // GPIO1_14 { GPIO = 46}
#define P8_17 0x1b00 // GPIO0_27 { GPIO = 27}
#define P8_18 0x4100 // GPIO2_1 { GPIO = 65}
#define P8_19 0x1604 // EHRPWM2A { GPIO = 22, PWM_MUX_MODE = 4 }
#define P8_20 0x3f00 // GPIO1_31 { GPIO = 63}
#define P8_21 0x3e00 // GPIO1_30 { GPIO = 62}
#define P8_22 0x2500 // GPIO1_5 { GPIO = 37}
#define P8_23 0x2400 // GPIO1_4 { GPIO = 36}
#define P8_24 0x2100 // GPIO1_1 { GPIO = 33}
#define P8_25 0x2000 // GPIO1_0 { GPIO = 32}
#define P8_26 0x3d00 // GPIO1_29 { GPIO = 61}
#define P8_27 0x5600 // GPIO2_22 { GPIO = 86}
#define P8_28 0x5800 // GPIO2_24 { GPIO = 88}
#define P8_29 0x5700 // GPIO2_23 { GPIO = 87}
#define P8_30 0x5900 // GPIO2_25 { GPIO = 89}
#define P8_31 0x0a00 // UART5_CTSN { GPIO = 10}
#define P8_32 0x0b00 // UART5_RTSN { GPIO = 11}
#define P8_33 0x0900 // UART4_RTSN { GPIO = 9}
#define P8_34 0x5102 // UART3_RTSN { GPIO = 81, PWM_MUX_MODE = 2 }
#define P8_35 0x0800 // UART4_CTSN { GPIO = 8}
#define P8_36 0x5002 // UART3_CTSN { GPIO = 80, PWM_MUX_MODE = 2 }
#define P8_37 0x4e00 // UART5_TXD { GPIO = 78}
#define P8_38 0x4f00 // UART5_RXD { GPIO = 79}
#define P8_39 0x4c00 // GPIO2_12 { GPIO = 76}
#define P8_40 0x4d00 // GPIO2_13 { GPIO = 77}
#define P8_41 0x4a00 // GPIO2_10 { GPIO = 74}
#define P8_42 0x4b00 // GPIO2_11 { GPIO = 75}
#define P8_43 0x4800 // GPIO2_8 { GPIO = 72}
#define P8_44 0x4900 // GPIO2_9 { GPIO = 73}
#define P8_45 0x4603 // GPIO2_6 { GPIO = 70, PWM_MUX_MODE = 3 }
#define P8_46 0x4703 // GPIO2_7 { GPIO = 71, PWM_MUX_MODE = 3 }
#define P9_1  0x0000 // DGND
#define P9_2  0x0000 // DGND
#define P9_3  0x0000 // VDD_3V3
#define P9_4  0x0000 // VDD_3V3
#define P9_5  0x0000 // VDD_5V
#define P9_6  0x0000 // VDD_5V
#define P9_7  0x0000 // SYS_5V
#define P9_8  0x0000 // SYS_5V
#define P9_9  0x0000 // PWR_BUT
#define P9_10 0x0000 // SYS_RESETn
#define P9_11 0x1e00 // UART4_RXD { GPIO = 30}
#define P9_12 0x3c00 // GPIO1_28 { GPIO = 60}
#define P9_13 0x1f00 // UART4_TXD { GPIO = 31}
#define P9_14 0x3206 // EHRPWM1A { GPIO = 50, PWM_MUX_MODE = 6 }
#define P9_15 0x3000 // GPIO1_16 { GPIO = 48}
#define P9_16 0x3306 // EHRPWM1B { GPIO = 51, PWM_MUX_MODE = 6 }
#define P9_17 0x0500 // I2C1_SCL { GPIO = 5}
#define P9_18 0x0400 // I2C1_SDA { GPIO = 4}
#define P9_19 0x0d00 // I2C2_SCL { GPIO = 13}
#define P9_20 0x0c00 // I2C2_SDA { GPIO = 12}
#define P9_21 0x0303 // UART2_TXD { GPIO = 3, PWM_MUX_MODE = 3 }
#define P9_22 0x0203 // UART2_RXD { GPIO = 2, PWM_MUX_MODE = 3 }
#define P9_23 0x3100 // GPIO1_17 { GPIO = 49}
#define P9_24 0x0f00 // UART1_TXD { GPIO = 15}
#define P9_25 0x7500 // GPIO3_21 { GPIO = 117}
#define P9_26 0x0e00 // UART1_RXD { GPIO = 14}
#define P9_27 0x7300 // GPIO3_19 { GPIO = 115}
#define P9_28 0x7104 // SPI1_CS0 { GPIO = 113, PWM_MUX_MODE = 4 }
#define P9_29 0x6f01 // SPI1_D0 { GPIO = 111, PWM_MUX_MODE = 1 }
#define P9_30 0x7000 // SPI1_D1 { GPIO = 112}
#define P9_31 0x6e01 // SPI1_SCLK { GPIO = 110, PWM_MUX_MODE = 1 }
#define P9_32 0x0000 // VDD_ADC
#define P9_33 0x0040 // AIN4 { AIN = 4 }
#define P9_34 0x0000 // GNDA_ADC
#define P9_35 0x0060 // AIN6 { AIN = 6 }
#define P9_36 0x0050 // AIN5 { AIN = 5 }
#define P9_37 0x0020 // AIN2 { AIN = 2 }
#define P9_38 0x0030 // AIN3 { AIN = 3 }
#define P9_39 0x0000 // AIN0
#define P9_40 0x0010 // AIN1 { AIN = 1 }
#define P9_41 0x1400 // CLKOUT2 { GPIO = 20}
#define P9_42 0x0700 // GPIO0_7 { GPIO = 7}
#define P9_43 0x0000 // DGND
#define P9_44 0x0000 // DGND
#define P9_45 0x0000 // DGND
#define P9_46 0x0000 // DGND
  
int beaglebone_gpio(const unsigned int);
int beaglebone_ain(const unsigned int);
int beaglebone_pwm_mux_mode(const unsigned int);

#ifdef __cplusplus
}
#endif

#endif