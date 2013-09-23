/*
 
 adc.h
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

#ifndef BONEKIT_ADC_H__
#define BONEKIT_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#define ADC_DIR "/sys/bus/iio/devices/iio:device0"
#define ADC_LEN 64
  
#define ADC_MAX_VALUE 4095 // 12 bit ADC
#define ADC_MIN_VALUE 0
  
#define ADC_THRESHOLD 2048 // High, value > threshold

int adc_read(unsigned int, char *, unsigned int);
int adc_get_value(unsigned int, unsigned int *);

#ifdef __cplusplus
}
#endif

#endif