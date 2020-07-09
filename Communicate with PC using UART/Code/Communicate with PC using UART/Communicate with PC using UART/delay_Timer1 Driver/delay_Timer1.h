//****************************************************************************
 #ifndef	DELAY_TIMER1_H_
 #define	DELAY_TIMER1_H_

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "Timer_1_REG.h"
 
 
 #define	F_CPU	16000000UL
  
  
 //	Functions Prototypes
 void delay_us_Timer1(u16 microseconds);
 void delay_ms_Timer1(u16 milliseconds);
 void delay_s_Timer1(u8 seconds);


#endif
//****************************************************************************