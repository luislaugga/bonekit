/*
*/

#ifndef BONEKIT_HMC5883L_H__
#define BONEKIT_HMC5883L_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c-dev.h>
#include <math.h>

#define HMC5883L_Address 0x1E
#define HMC5883L_Name "HMC5883L"
#define ConfigurationRegisterA 0x00
#define ConfigurationRegisterB 0x01
#define ModeRegister 0x02
#define DataRegisterBegin 0x03

#define Measurement_Continuous 0x00
#define Measurement_SingleShot 0x01
#define Measurement_Idle 0x03

#define ErrorCode_1 "Scalenotvalid"//Entered scale was not valid, valid gauss values are: 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1"
#define ErrorCode_1_Num 1

typedef struct
{
	float XAxis;
	float YAxis;
	float ZAxis;
} hmc5883l_scaled_t;

typedef struct
{
	int XAxis;
	int YAxis;
	int ZAxis;
} hmc5883l_raw_t;

struct hmc5883l_s
{
  float _scale;
  float _fd;
  float _buffer[32];
};

typedef struct hmc5883l_s hmc5883l_t;

hmc5883l_t * hmc5883l_create();
void hmc5883l_destroy(hmc5883l_t *);
float hmc5883l_heading(hmc5883l_t *);

#ifdef __cplusplus
}
#endif

#endif