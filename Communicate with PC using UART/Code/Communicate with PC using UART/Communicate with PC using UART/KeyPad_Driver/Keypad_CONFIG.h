//****************************************************************************
#ifndef		KEYPAD_CONFIG_H_
#define		KEYPAD_CONFIG_H_


//	Clock	Frequency
#ifndef F_CPU
#define F_CPU 16000000UL						 // 1 MHz clock speed
#endif


//	Select the Used Port
#define		KeypadPORT			portB	


//	Select the Used Pins
#define		C1					0
#define		C2					1
#define		C3					2
#define		C4					3

#define		R1					4
#define		R2					5
#define		R3					6
#define		R4					7


//	Select the Dimensions for the KeyPad
#define		COL					4
#define		ROW					4


//	Define Columns and Rows of KeyPad
static	volatile u8 Columns[COL]  = {C4,C3,C2,C1};
static	volatile u8 Rows[ROW]	  = {R4,R3,R2,R1};


//	Define the Buttons of the KeyPad
static	volatile u8 Keypad_Buttons[ROW][COL] = { {'1','2','3','A'},
												 {'4','5','6','B'},
												 {'7','8','9','C'},
												 {'*','0','#','D'}  };

//	End of Configuration

#endif
//****************************************************************************
