
#ifndef _H7SEG_PRIVATE_H_
#define _H7SEG_PRIVATE_H_

	//int [MAX_DIGITS][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},};

/*comman cathod 7segment*/
	u8 Local_ArrPinstate_cc[10][9]={
	  /*{a,b,c,d,e,f,g,dp}*/
		{1,1,1,1,1,1,0,0} ,
		{0,1,1,0,0,0,0,0} ,      /*1*/
		{1,1,0,1,1,0,1,0} ,   	/*2*/
		{1,1,1,1,0,0,1,0} ,     /*3*/
		{0,1,1,0,0,1,1,0} ,		/*4*/
		{1,0,1,1,0,1,1,0} ,
		{1,0,1,1,1,1,1,0} ,
		{1,1,1,0,0,0,0,0} ,
		{1,1,1,1,1,1,1,0} ,
		{1,1,1,1,0,1,1,0} ,



	};

#define AVR_CONTROLLER 				0
#define ARM_CONTROLLER 				1


#define PIN_LOW    0
#define PIN_HIGH   1

#define MGPIO_PORTA  0
#define MGPIO_PORTB  1
#define MGPIO_PORTC  2

#define MGPIO_PIN0   0
#define MGPIO_PIN1   1
#define MGPIO_PIN2   2
#define MGPIO_PIN3   3
#define MGPIO_PIN4   4
#define MGPIO_PIN5   5
#define MGPIO_PIN6   6
#define MGPIO_PIN7   7
#define MGPIO_PIN8   8
#define MGPIO_PIN9   9
#define MGPIO_PIN10  10
#define MGPIO_PIN11  11
#define MGPIO_PIN12  12
#define MGPIO_PIN13  13
#define MGPIO_PIN14  14
#define MGPIO_PIN15  15





 #define MGPIO_OUTPUT_2MHZ_PP          0b0010
 #define MGPIO_OUTPUT_2MHZ_OP          0b0110
 #define MGPIO_OUTPUT_10MHZ_PP         0b0001
 #define MGPIO_OUTPUT_10MHZ_OP         0b0101









#endif
