/*
 
 gpio.h
 BoneKit
 
 Copyright (cc) 2012 Luis Laugga.
 Some rights reserved, all wrongs deserved.
 
 Licensed under a Creative Commons Attribution-ShareAlike 3.0 License;
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://creativecommons.org/licenses/by-sa/3.0/
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" basis,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
*/

#ifndef BONEKIT_GPIO_H__
#define BONEKIT_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#define INPUT  0
#define OUTPUT 1

#define HIGH 1
#define LOW  0
  
#define GPIO_DIR "/sys/class/gpio"
#define GPIO_LEN 64

int gpio_read(unsigned int, const char * , char *);
int gpio_write(unsigned int, const char *, char *);

int gpio_export(unsigned int);
int gpio_unexport(unsigned int);

int gpio_set_direction(unsigned int, unsigned int);
int gpio_get_direction(unsigned int, unsigned int*);

int gpio_set_value(unsigned int, unsigned int);
int gpio_get_value(unsigned int, unsigned int*);

#ifdef __cplusplus
}
#endif

#endif