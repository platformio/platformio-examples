/**
* \defgroup EngduinoMagnetometer Driver for Engduino Magnetometer
* 
* @{
*/

/**
* \file 
* 		Engduino Magnetometer driver
* \author
* 		Engduino team: support@engduino.org
*/

#ifndef __ENGDUINOMAGNETOMETER_H__
#define __ENGDUINOMAGNETOMETER_H__

#include <stdio.h>
#include <Arduino.h>
#include <Engduino.h>

#if defined (__BOARD_ENGDUINOV2) || defined(__BOARD_ENGDUINOV3)

/***********************************************************************************************\
* Public macros
\***********************************************************************************************/

// 7 Bit I2C Device Address
#define FXMS3110_IIC_ADDRESS       (0x0E) 

/***********************************************************************************************
**
**  FXMS3110Q Sensor Internal Registers
*/
enum
{
  FXMS3110_DR_STATUS = 0,          // 0x00
  FXMS3110_OUT_X_MSB,              // 0x01
  FXMS3110_OUT_X_LSB,              // 0x02
  FXMS3110_OUT_Y_MSB,              // 0x03
  FXMS3110_OUT_Y_lSB,              // 0x04
  FXMS3110_OUT_Z_MSB,              // 0x05
  FXMS3110_OUT_Z_LSB,              // 0x06
  FXMS3110_WHO_AM_I,               // 0x07
  FXMS3110_SYSMOD,           	   // 0x08
  FXMS3110_OFF_X_MSB,              // 0x09
  FXMS3110_OFF_X_LSB,              // 0x0A
  FXMS3110_OFF_Y_MSB,              // 0x0B
  FXMS3110_OFF_Y_LSB,              // 0x0C
  FXMS3110_OFF_Z_MSB,              // 0x0D
  FXMS3110_OFF_Z_LSB,              // 0x0E
  FXMS3110_DIE_TEMP,               // 0x0F
  FXMS3110_CTRL_REG1,              // 0x10
  FXMS3110_CTRL_REG2               // 0x11
};

/*
**  DR_STATUS Register
*/
#define DR_STATUS_REG         0x00
//
#define ZYXOW_BIT             Bit._7
#define ZOW_BIT               Bit._6
#define YOW_BIT               Bit._5
#define XOW_BIT               Bit._4
#define ZYXDR_BIT             Bit._3
#define ZDR_BIT               Bit._2
#define YDR_BIT               Bit._1
#define XDR_BIT               Bit._0
//
#define ZYXOW_MASK            0x80
#define ZOW_MASK              0x40
#define YOW_MASK              0x20
#define XOW_MASK              0x10
#define ZYXDR_MASK            0x08
#define ZDR_MASK              0x04
#define YDR_MASK              0x02
#define XDR_MASK              0x01


/*
**  XYZ Data Registers
*/
#define OUT_X_MSB_REG         0x01
#define OUT_X_LSB_REG         0x02
#define OUT_Y_MSB_REG         0x03
#define OUT_Y_LSB_REG         0x04
#define OUT_Z_MSB_REG         0x05
#define OUT_Z_LSB_REG         0x06

/*
**  WHO_AM_I Device ID Register
*/
#define WHO_AM_I_REG          0x07
//
#define FXMS3110              0xC4


/*
**  SYSMOD System Mode Register
**  MMA8652 only
*/
#define SYSMOD_REG            0x08
//
#define SYSMOD1_BIT           Bit._1
#define SYSMOD0_BIT           Bit._0
//
#define SYSMOD1_MASK          0x02
#define SYSMOD0_MASK          0x01
#define SYSMOD_MASK           0x03
//
#define SYSMOD_STANDBY        0x00
#define SYSMOD_ACTIVE_RAW     (SYSMOD0_MASK)
#define SYSMOD_ACTIVE_USER    (SYSMOD1_MASK)

/*
**  XYZ Offset Correction Registers
*/
#define OFF_X_MSB_REG         0x09
#define OFF_X_LSB_REG         0x0A
#define OFF_Y_MSB_REG         0x0B
#define OFF_Y_LSB_REG         0x0C
#define OFF_Z_MSB_REG         0x0D
#define OFF_Z_LSB_REG         0x0E

/*
**  Die Temperature Register
*/
#define OFF_X_MSB_REG         0x0F

/*
**  CTRL_REG1 System Control 1 Register
*/
#define CTRL_REG1             0x10
//
#define DR2_BIT               Bit._7
#define DR1_BIT               Bit._6
#define DR0_BIT               Bit._5
#define OS1_BIT               Bit._4
#define OS0_BIT               Bit._3
#define FREAD_BIT             Bit._2
#define TM_BIT                Bit._1
#define ACTIVE_BIT            Bit._0
//
#define DR2_MASK              0x80
#define DR1_MASK              0x40
#define DR0_MASK              0x20
#define OS1_MASK              0x10
#define OS0_MASK              0x08
#define FREAD_MASK            0x04
#define TM_MASK               0x02
#define ACTIVE_MASK           0x01
#define DR_MASK				  (DR2_MASK+DR1_MASK+DR0_MASK)
#define OS_MASK				  (OS1_MASK+OS0_MASK)
// The values are formed as ADCrate_Oversampling 
#define DATA_RATE_1280_16     0x00
#define DATA_RATE_1280_32     (OS0_MASK)
#define DATA_RATE_1280_64     (OS1_MASK)
#define DATA_RATE_1280_128    (OS0_MASK+OS1_MASK)
#define DATA_RATE_640_16      (DR0)
#define DATA_RATE_640_32      (DR0+OS0_MASK)
#define DATA_RATE_640_64      (DR0+OS1_MASK)
#define DATA_RATE_640_128     (DR0+OS0_MASK+OS1_MASK)
#define DATA_RATE_320_16      (DR1)
#define DATA_RATE_320_32      (DR1+OS0_MASK)
#define DATA_RATE_320_64      (DR1+OS1_MASK)
#define DATA_RATE_320_128     (DR1+OS0_MASK+OS1_MASK)
#define DATA_RATE_160_16      (DR0+DR1)
#define DATA_RATE_160_32      (DR0+DR1+OS0_MASK)
#define DATA_RATE_160_64      (DR0+DR1+OS1_MASK)
#define DATA_RATE_160_128     (DR0+DR1+OS0_MASK+OS1_MASK)
#define DATA_RATE_80_16       (DR2)
#define DATA_RATE_80_32       (DR2+OS0_MASK)
#define DATA_RATE_80_64       (DR2+OS1_MASK)
#define DATA_RATE_80_128      (DR2+OS0_MASK+OS1_MASK)
// There are others, but no easy way of naming them directly because of overloading.
// See table 32 in the data sheet
//
#define TRIGGER_OFF           0x00
#define TRIGGER_ON            (ACTIVE_MASK)
#define ACTIVE                (ACTIVE_MASK)
#define STANDBY               0x00

/*
**  CTRL_REG2 System Control 2 Register
*/
#define CTRL_REG2             0x11
//
#define AUTO_MRST_EN_BIT      Bit._7
#define RAW_BIT               Bit._5
#define MAG_RST_BIT           Bit._4
//
#define AUTO_MRST_EN_MASK     0x80
#define RAW_MASK          	  0x20
#define MAG_RST_MASK          0x10
//

/***********************************************************************************************\
* Public type definitions
\***********************************************************************************************/

/***********************************************************************************************\
* Public memory declarations
\***********************************************************************************************/

/***********************************************************************************************\
* Public prototypes
\***********************************************************************************************/

class EngduinoMagnetometerClass 
{
	private:
		void activate();
		void standby();
		void writeReg(int firstReg, const uint8_t *buf, uint8_t nRegs=1);
		void readReg(int firstReg, uint8_t *buf, uint8_t nRegs=1);
	
	public:
		EngduinoMagnetometerClass();
		void   begin();
		void   end();
		void   xyz(float buf[3]);
		int8_t temperature();

};

extern EngduinoMagnetometerClass EngduinoMagnetometer;

#endif
#endif
/** @} */
