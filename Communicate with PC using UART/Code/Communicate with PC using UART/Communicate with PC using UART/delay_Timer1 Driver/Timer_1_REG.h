//****************************************************************************
 #ifndef	TIMER_1_REG_H_
 #define	TIMER_1_REG_H_
 
 
 
//	Timer_1 Registers
#ifndef	TCCR1A
#define TCCR1A						(*((volatile u8*)(0x4F)))
#endif


#ifndef	TCCR1B
#define TCCR1B						(*((volatile u8*)(0x4E)))
#endif



#ifndef	OCR1AL
#define OCR1AL						(*((volatile u8*)(0x4A)))
#endif



#ifndef	OCR1AH
#define OCR1AH						(*((volatile u8*)(0x4B)))
#endif



#ifndef	ICR1L
#define ICR1L 						(*((volatile u8*)(0x46)))
#endif



#ifndef	ICR1H 
#define ICR1H 						(*((volatile u8*)(0x47)))
#endif





#ifndef	SFIOR
#define SFIOR						(*((volatile u8*)(0x50)))
#endif



#ifndef	TIFR
#define TIFR						(*((volatile u8*)(0x58)))
#endif

#ifndef	TIMSK
#define TIMSK						(*((volatile u8*)(0x59)))
#endif



//	Timer_1 Registers Bits
//  TCCR1A Register
#define			WGM10								0
#define			WGM11								1
#define			COM1B0								4
#define			COM1B1								5
#define			COM1A0								6
#define			COM1A1								7



//  TCCR1B Register
#define			CS10								0
#define			CS11								1
#define			CS12								2
#define			WGM12								3
#define			WGM13								4
#define			ICES1								6
#define			ICNC1								7


//  TIMSK Register
#define			OCIE1A								4
#define			TICIE1								5


//  SFIOR Register
#define			PSR10								0


//  TIFR Register
#define			OCF1A 								4
#define			ICF1 								5

 
#endif
//****************************************************************************