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

#define INPUT  0
#define OUTPUT 1

#define HIGH 1
#define LOW  0
  
#define PIN_NAME_LEN 6
  
struct beaglebone_s { 
  const char pin_name[PIN_NAME_LEN]; 
  const int pin_mask;
};

typedef struct beaglebone_s beaglebone_t;

// Bit mask = GPIO (0-7), AIN (8-15), PWM (16-23)
#define USR0  ((beaglebone_t){"USR0", 0x35ffff}) // USR0 { GPIO = 53 }
#define USR1  ((beaglebone_t){"USR1", 0x36ffff}) // USR1 { GPIO = 54 }
#define USR2  ((beaglebone_t){"USR2", 0x37ffff}) // USR2 { GPIO = 55 }
#define USR3  ((beaglebone_t){"USR3", 0x38ffff}) // USR3 { GPIO = 56 }
#define P8_1  ((beaglebone_t){"P8_1", 0xffffff}) // DGND
#define P8_2  ((beaglebone_t){"P8_2", 0xffffff}) // DGND
#define P8_3  ((beaglebone_t){"P8_3", 0x26ffff}) // GPIO1_6 { GPIO = 38 }
#define P8_4  ((beaglebone_t){"P8_4", 0x27ffff}) // GPIO1_7 { GPIO = 39 }
#define P8_5  ((beaglebone_t){"P8_5", 0x22ffff}) // GPIO1_2 { GPIO = 34 }
#define P8_6  ((beaglebone_t){"P8_6", 0x23ffff}) // GPIO1_3 { GPIO = 35 }
#define P8_7  ((beaglebone_t){"P8_7", 0x42ffff}) // TIMER4 { GPIO = 66 }
#define P8_8  ((beaglebone_t){"P8_8", 0x43ffff}) // TIMER7 { GPIO = 67 }
#define P8_9  ((beaglebone_t){"P8_9", 0x45ffff}) // TIMER5 { GPIO = 69 }
#define P8_10 ((beaglebone_t){"P8_10", 0x44ffff}) // TIMER6 { GPIO = 68 }
#define P8_11 ((beaglebone_t){"P8_11", 0x2dffff}) // GPIO1_13 { GPIO = 45 }
#define P8_12 ((beaglebone_t){"P8_12", 0x2cffff}) // GPIO1_12 { GPIO = 44 }
#define P8_13 ((beaglebone_t){"P8_13", 0x17ff04}) // EHRPWM2B { GPIO = 23, PWM_MUX_MODE = 4 }
#define P8_14 ((beaglebone_t){"P8_14", 0x1affff}) // GPIO0_26 { GPIO = 26 }
#define P8_15 ((beaglebone_t){"P8_15", 0x2fffff}) // GPIO1_15 { GPIO = 47 }
#define P8_16 ((beaglebone_t){"P8_16", 0x2effff}) // GPIO1_14 { GPIO = 46 }
#define P8_17 ((beaglebone_t){"P8_17", 0x1bffff}) // GPIO0_27 { GPIO = 27 }
#define P8_18 ((beaglebone_t){"P8_18", 0x41ffff}) // GPIO2_1 { GPIO = 65 }
#define P8_19 ((beaglebone_t){"P8_19", 0x16ff04}) // EHRPWM2A { GPIO = 22, PWM_MUX_MODE = 4 }
#define P8_20 ((beaglebone_t){"P8_20", 0x3fffff}) // GPIO1_31 { GPIO = 63 }
#define P8_21 ((beaglebone_t){"P8_21", 0x3effff}) // GPIO1_30 { GPIO = 62 }
#define P8_22 ((beaglebone_t){"P8_22", 0x25ffff}) // GPIO1_5 { GPIO = 37 }
#define P8_23 ((beaglebone_t){"P8_23", 0x24ffff}) // GPIO1_4 { GPIO = 36 }
#define P8_24 ((beaglebone_t){"P8_24", 0x21ffff}) // GPIO1_1 { GPIO = 33 }
#define P8_25 ((beaglebone_t){"P8_25", 0x20ffff}) // GPIO1_0 { GPIO = 32 }
#define P8_26 ((beaglebone_t){"P8_26", 0x3dffff}) // GPIO1_29 { GPIO = 61 }
#define P8_27 ((beaglebone_t){"P8_27", 0x56ffff}) // GPIO2_22 { GPIO = 86 }
#define P8_28 ((beaglebone_t){"P8_28", 0x58ffff}) // GPIO2_24 { GPIO = 88 }
#define P8_29 ((beaglebone_t){"P8_29", 0x57ffff}) // GPIO2_23 { GPIO = 87 }
#define P8_30 ((beaglebone_t){"P8_30", 0x59ffff}) // GPIO2_25 { GPIO = 89 }
#define P8_31 ((beaglebone_t){"P8_31", 0x0affff}) // UART5_CTSN { GPIO = 10 }
#define P8_32 ((beaglebone_t){"P8_32", 0x0bffff}) // UART5_RTSN { GPIO = 11 }
#define P8_33 ((beaglebone_t){"P8_33", 0x09ffff}) // UART4_RTSN { GPIO = 9 }
#define P8_34 ((beaglebone_t){"P8_34", 0x51ff02}) // UART3_RTSN { GPIO = 81, PWM_MUX_MODE = 2 }
#define P8_35 ((beaglebone_t){"P8_35", 0x08ffff}) // UART4_CTSN { GPIO = 8 }
#define P8_36 ((beaglebone_t){"P8_36", 0x50ff02}) // UART3_CTSN { GPIO = 80, PWM_MUX_MODE = 2 }
#define P8_37 ((beaglebone_t){"P8_37", 0x4effff}) // UART5_TXD { GPIO = 78 }
#define P8_38 ((beaglebone_t){"P8_38", 0x4fffff}) // UART5_RXD { GPIO = 79 }
#define P8_39 ((beaglebone_t){"P8_39", 0x4cffff}) // GPIO2_12 { GPIO = 76 }
#define P8_40 ((beaglebone_t){"P8_40", 0x4dffff}) // GPIO2_13 { GPIO = 77 }
#define P8_41 ((beaglebone_t){"P8_41", 0x4affff}) // GPIO2_10 { GPIO = 74 }
#define P8_42 ((beaglebone_t){"P8_42", 0x4bffff}) // GPIO2_11 { GPIO = 75 }
#define P8_43 ((beaglebone_t){"P8_43", 0x48ffff}) // GPIO2_8 { GPIO = 72 }
#define P8_44 ((beaglebone_t){"P8_44", 0x49ffff}) // GPIO2_9 { GPIO = 73 }
#define P8_45 ((beaglebone_t){"P8_45", 0x46ff03}) // GPIO2_6 { GPIO = 70, PWM_MUX_MODE = 3 }
#define P8_46 ((beaglebone_t){"P8_46", 0x47ff03}) // GPIO2_7 { GPIO = 71, PWM_MUX_MODE = 3 }
#define P9_1  ((beaglebone_t){"P9_1", 0xffffff}) // DGND
#define P9_2  ((beaglebone_t){"P9_2", 0xffffff}) // DGND
#define P9_3  ((beaglebone_t){"P9_3", 0xffffff}) // VDD_3V3
#define P9_4  ((beaglebone_t){"P9_4", 0xffffff}) // VDD_3V3
#define P9_5  ((beaglebone_t){"P9_5", 0xffffff}) // VDD_5V
#define P9_6  ((beaglebone_t){"P9_6", 0xffffff}) // VDD_5V
#define P9_7  ((beaglebone_t){"P9_7", 0xffffff}) // SYS_5V
#define P9_8  ((beaglebone_t){"P9_8", 0xffffff}) // SYS_5V
#define P9_9  ((beaglebone_t){"P9_9", 0xffffff}) // PWR_BUT
#define P9_10 ((beaglebone_t){"P9_10", 0xffffff}) // SYS_RESETn
#define P9_11 ((beaglebone_t){"P9_11", 0x1effff}) // UART4_RXD { GPIO = 30 }
#define P9_12 ((beaglebone_t){"P9_12", 0x3cffff}) // GPIO1_28 { GPIO = 60 }
#define P9_13 ((beaglebone_t){"P9_13", 0x1fffff}) // UART4_TXD { GPIO = 31 }
#define P9_14 ((beaglebone_t){"P9_14", 0x32ff06}) // EHRPWM1A { GPIO = 50, PWM_MUX_MODE = 6 }
#define P9_15 ((beaglebone_t){"P9_15", 0x30ffff}) // GPIO1_16 { GPIO = 48 }
#define P9_16 ((beaglebone_t){"P9_16", 0x33ff06}) // EHRPWM1B { GPIO = 51, PWM_MUX_MODE = 6 }
#define P9_17 ((beaglebone_t){"P9_17", 0x05ffff}) // I2C1_SCL { GPIO = 5 }
#define P9_18 ((beaglebone_t){"P9_18", 0x04ffff}) // I2C1_SDA { GPIO = 4 }
#define P9_19 ((beaglebone_t){"P9_19", 0x0dffff}) // I2C2_SCL { GPIO = 13 }
#define P9_20 ((beaglebone_t){"P9_20", 0x0cffff}) // I2C2_SDA { GPIO = 12 }
#define P9_21 ((beaglebone_t){"P9_21", 0x03ff03}) // UART2_TXD { GPIO = 3, PWM_MUX_MODE = 3 }
#define P9_22 ((beaglebone_t){"P9_22", 0x02ff03}) // UART2_RXD { GPIO = 2, PWM_MUX_MODE = 3 }
#define P9_23 ((beaglebone_t){"P9_23", 0x31ffff}) // GPIO1_17 { GPIO = 49 }
#define P9_24 ((beaglebone_t){"P9_24", 0x0fffff}) // UART1_TXD { GPIO = 15 }
#define P9_25 ((beaglebone_t){"P9_25", 0x75ffff}) // GPIO3_21 { GPIO = 117 }
#define P9_26 ((beaglebone_t){"P9_26", 0x0effff}) // UART1_RXD { GPIO = 14 }
#define P9_27 ((beaglebone_t){"P9_27", 0x73ffff}) // GPIO3_19 { GPIO = 115 }
#define P9_28 ((beaglebone_t){"P9_28", 0x71ff04}) // SPI1_CS0 { GPIO = 113, PWM_MUX_MODE = 4 }
#define P9_29 ((beaglebone_t){"P9_29", 0x6fff01}) // SPI1_D0 { GPIO = 111, PWM_MUX_MODE = 1 }
#define P9_30 ((beaglebone_t){"P9_30", 0x70ffff}) // SPI1_D1 { GPIO = 112 }
#define P9_31 ((beaglebone_t){"P9_31", 0x6eff01}) // SPI1_SCLK { GPIO = 110, PWM_MUX_MODE = 1 }
#define P9_32 ((beaglebone_t){"P9_32", 0xffffff}) // VDD_ADC
#define P9_33 ((beaglebone_t){"P9_33", 0xff04ff}) // AIN4 { AIN = 4 }
#define P9_34 ((beaglebone_t){"P9_34", 0xffffff}) // GNDA_ADC
#define P9_35 ((beaglebone_t){"P9_35", 0xff06ff}) // AIN6 { AIN = 6 }
#define P9_36 ((beaglebone_t){"P9_36", 0xff05ff}) // AIN5 { AIN = 5 }
#define P9_37 ((beaglebone_t){"P9_37", 0xff02ff}) // AIN2 { AIN = 2 }
#define P9_38 ((beaglebone_t){"P9_38", 0xff03ff}) // AIN3 { AIN = 3 }
#define P9_39 ((beaglebone_t){"P9_39", 0xff00ff}) // AIN0 { AIN = 0 }
#define P9_40 ((beaglebone_t){"P9_40", 0xff01ff}) // AIN1 { AIN = 1 }
#define P9_41 ((beaglebone_t){"P9_41", 0x14ffff}) // CLKOUT2 { GPIO = 20 }
#define P9_42 ((beaglebone_t){"P9_42", 0x07ff00}) // GPIO0_7 { GPIO = 7, PWM_MUX_MODE = 0 }
#define P9_43 ((beaglebone_t){"P9_43", 0xffffff}) // DGND
#define P9_44 ((beaglebone_t){"P9_44", 0xffffff}) // DGND
#define P9_45 ((beaglebone_t){"P9_45", 0xffffff}) // DGND
#define P9_46 ((beaglebone_t){"P9_46", 0xffffff}) // DGND

void beaglebone_pin_name(beaglebone_t, char *); // ie. "P9_42"
int beaglebone_gpio(beaglebone_t);
int beaglebone_ain(beaglebone_t);
int beaglebone_pwm_mux_mode(beaglebone_t);

#ifdef __cplusplus
}
#endif

#endif