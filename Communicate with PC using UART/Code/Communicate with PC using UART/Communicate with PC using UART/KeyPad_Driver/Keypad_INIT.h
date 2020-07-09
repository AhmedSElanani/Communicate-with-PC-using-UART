//****************************************************************************
#ifndef		KEYPAD_INIT_H_
#define		KEYPAD_INIT_H_


#include "../DIO Driver/DIO_INIT.h"
#include "Keypad_CONFIG.h"
#include <util/delay.h>


void Vid_Keypad_INIT(void);
u8 Keypad_GetPressed(void);
void Keypad_VidDelay_mS(u16 ms);


#endif
//****************************************************************************
