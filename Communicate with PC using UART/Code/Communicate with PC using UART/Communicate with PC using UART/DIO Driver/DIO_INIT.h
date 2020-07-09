//****************************************************************************
#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "DIO_REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//	List of Port Definitions
#define			portA		0
#define			portB		1
#define			portC		2
#define			portD		3


//	Directions definitions
#define			INPUT		0
#define			OUTPUT		1


//	Logic States definitions
#define			LOW			0
#define			HIGH		1


//	Functions Prototypes
void DIO_VidSetPinDirection(u8 PinNumber, u8 PortNumber, u8 Direction);						//DIO --> Module Name  , Vid --> Returns Void
void DIO_VidSetPinValue(u8 PinNumber, u8 PortNumber, u8 Value);

void DIO_VidSetPortDirection( u8 PortNumber, u8 Direction);
void DIO_VidSetPortValue( u8 PortNumber,u8 Value);

u8 DIO_U8GetPinValue(u8 PinNumber, u8 PortNumber);											//DIO --> Module Name  , U8 --> Returns U8
u8 DIO_U8GetPortValue( u8 PortNumber);

#endif
//****************************************************************************

