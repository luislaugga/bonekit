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

// Global constants
#define INPUT  0
#define OUTPUT 1
#define PWM    2

// Bit mask = GPIO (0-7), AIN (8-15), PWM (16-23)
#define USR0  0x010035ffff // USR0 { GPIO = 53 }
#define USR1  0x010136ffff // USR1 { GPIO = 54 }
#define USR2  0x010237ffff // USR2 { GPIO = 55 }
#define USR3  0x010338ffff // USR3 { GPIO = 56 }
#define P8_1  0x0801ffffff // DGND
#define P8_2  0x0802ffffff // DGND
#define P8_3  0x080326ffff // GPIO1_6 { GPIO = 38 }
#define P8_4  0x080427ffff // GPIO1_7 { GPIO = 39 }
#define P8_5  0x080522ffff // GPIO1_2 { GPIO = 34 }
#define P8_6  0x080623ffff // GPIO1_3 { GPIO = 35 }
#define P8_7  0x080742ffff // TIMER4 { GPIO = 66 }
#define P8_8  0x080843ffff // TIMER7 { GPIO = 67 }
#define P8_9  0x080945ffff // TIMER5 { GPIO = 69 }
#define P8_10 0x080a44ffff // TIMER6 { GPIO = 68 }
#define P8_11 0x080b2dffff // GPIO1_13 { GPIO = 45 }
#define P8_12 0x080c2cffff // GPIO1_12 { GPIO = 44 }
#define P8_13 0x080d17ff04 // EHRPWM2B { GPIO = 23, PWM_MUX_MODE = 4 }
#define P8_14 0x080e1affff // GPIO0_26 { GPIO = 26 }
#define P8_15 0x080f2fffff // GPIO1_15 { GPIO = 47 }
#define P8_16 0x08102effff // GPIO1_14 { GPIO = 46 }
#define P8_17 0x08111bffff // GPIO0_27 { GPIO = 27 }
#define P8_18 0x081241ffff // GPIO2_1 { GPIO = 65 }
#define P8_19 0x081316ff04 // EHRPWM2A { GPIO = 22, PWM_MUX_MODE = 4 }
#define P8_20 0x08143fffff // GPIO1_31 { GPIO = 63 }
#define P8_21 0x08153effff // GPIO1_30 { GPIO = 62 }
#define P8_22 0x081625ffff // GPIO1_5 { GPIO = 37 }
#define P8_23 0x081724ffff // GPIO1_4 { GPIO = 36 }
#define P8_24 0x081821ffff // GPIO1_1 { GPIO = 33 }
#define P8_25 0x081920ffff // GPIO1_0 { GPIO = 32 }
#define P8_26 0x081a3dffff // GPIO1_29 { GPIO = 61 }
#define P8_27 0x081b56ffff // GPIO2_22 { GPIO = 86 }
#define P8_28 0x081c58ffff // GPIO2_24 { GPIO = 88 }
#define P8_29 0x081d57ffff // GPIO2_23 { GPIO = 87 }
#define P8_30 0x081e59ffff // GPIO2_25 { GPIO = 89 }
#define P8_31 0x081f0affff // UART5_CTSN { GPIO = 10 }
#define P8_32 0x08200bffff // UART5_RTSN { GPIO = 11 }
#define P8_33 0x082109ffff // UART4_RTSN { GPIO = 9 }
#define P8_34 0x082251ff02 // UART3_RTSN { GPIO = 81, PWM_MUX_MODE = 2 }
#define P8_35 0x082308ffff // UART4_CTSN { GPIO = 8 }
#define P8_36 0x082450ff02 // UART3_CTSN { GPIO = 80, PWM_MUX_MODE = 2 }
#define P8_37 0x08254effff // UART5_TXD { GPIO = 78 }
#define P8_38 0x08264fffff // UART5_RXD { GPIO = 79 }
#define P8_39 0x08274cffff // GPIO2_12 { GPIO = 76 }
#define P8_40 0x08284dffff // GPIO2_13 { GPIO = 77 }
#define P8_41 0x08294affff // GPIO2_10 { GPIO = 74 }
#define P8_42 0x082a4bffff // GPIO2_11 { GPIO = 75 }
#define P8_43 0x082b48ffff // GPIO2_8 { GPIO = 72 }
#define P8_44 0x082c49ffff // GPIO2_9 { GPIO = 73 }
#define P8_45 0x082d46ff03 // GPIO2_6 { GPIO = 70, PWM_MUX_MODE = 3 }
#define P8_46 0x082e47ff03 // GPIO2_7 { GPIO = 71, PWM_MUX_MODE = 3 }
#define P9_1  0x0901ffffff // DGND
#define P9_2  0x0902ffffff // DGND
#define P9_3  0x0903ffffff // VDD_3V3
#define P9_4  0x0904ffffff // VDD_3V3
#define P9_5  0x0905ffffff // VDD_5V
#define P9_6  0x0906ffffff // VDD_5V
#define P9_7  0x0907ffffff // SYS_5V
#define P9_8  0x0908ffffff // SYS_5V
#define P9_9  0x0909ffffff // PWR_BUT
#define P9_10 0x090affffff // SYS_RESETn
#define P9_11 0x090b1effff // UART4_RXD { GPIO = 30 }
#define P9_12 0x090c3cffff // GPIO1_28 { GPIO = 60 }
#define P9_13 0x090d1fffff // UART4_TXD { GPIO = 31 }
#define P9_14 0x090e32ff06 // EHRPWM1A { GPIO = 50, PWM_MUX_MODE = 6 }
#define P9_15 0x090f30ffff // GPIO1_16 { GPIO = 48 }
#define P9_16 0x091033ff06 // EHRPWM1B { GPIO = 51, PWM_MUX_MODE = 6 }
#define P9_17 0x091105ffff // I2C1_SCL { GPIO = 5 }
#define P9_18 0x091204ffff // I2C1_SDA { GPIO = 4 }
#define P9_19 0x09130dffff // I2C2_SCL { GPIO = 13 }
#define P9_20 0x09140cffff // I2C2_SDA { GPIO = 12 }
#define P9_21 0x091503ff03 // UART2_TXD { GPIO = 3, PWM_MUX_MODE = 3 }
#define P9_22 0x091602ff03 // UART2_RXD { GPIO = 2, PWM_MUX_MODE = 3 }
#define P9_23 0x091731ffff // GPIO1_17 { GPIO = 49 }
#define P9_24 0x09180fffff // UART1_TXD { GPIO = 15 }
#define P9_25 0x091975ffff // GPIO3_21 { GPIO = 117 }
#define P9_26 0x091a0effff // UART1_RXD { GPIO = 14 }
#define P9_27 0x091b73ffff // GPIO3_19 { GPIO = 115 }
#define P9_28 0x091c71ff04 // SPI1_CS0 { GPIO = 113, PWM_MUX_MODE = 4 }
#define P9_29 0x091d6fff01 // SPI1_D0 { GPIO = 111, PWM_MUX_MODE = 1 }
#define P9_30 0x091e70ffff // SPI1_D1 { GPIO = 112 }
#define P9_31 0x091f6eff01 // SPI1_SCLK { GPIO = 110, PWM_MUX_MODE = 1 }
#define P9_32 0x0920ffffff // VDD_ADC
#define P9_33 0x0921ff04ff // AIN4 { AIN = 4 }
#define P9_34 0x0922ffffff // GNDA_ADC
#define P9_35 0x0923ff06ff // AIN6 { AIN = 6 }
#define P9_36 0x0924ff05ff // AIN5 { AIN = 5 }
#define P9_37 0x0925ff02ff // AIN2 { AIN = 2 }
#define P9_38 0x0926ff03ff // AIN3 { AIN = 3 }
#define P9_39 0x0927ff00ff // AIN0 { AIN = 0 }
#define P9_40 0x0928ff01ff // AIN1 { AIN = 1 }
#define P9_41 0x092914ffff // CLKOUT2 { GPIO = 20 }
#define P9_42 0x092a07ff00 // GPIO0_7 { GPIO = 7, PWM_MUX_MODE = 0 }
#define P9_43 0x092bffffff // DGND
#define P9_44 0x092cffffff // DGND
#define P9_45 0x092dffffff // DGND
#define P9_46 0x092effffff // DGND

void beaglebone_pin_name(const int, char **); // ie. "P9_42"
int beaglebone_gpio(const int);
int beaglebone_ain(const int);
int beaglebone_pwm_mux_mode(const int);

#ifdef __cplusplus
}
#endif

#endif