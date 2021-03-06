#ifndef _MGPIO_INTERFACE_H_
#define _MGPIO_INTERFACE_H_


#define MGPIO_OUTPUT	     			0
#define MGPIO_INPUT			      	0


#define MGPIO_LOW			        	0
#define	MGPIO_HIGH			      	1

#define MGPIO_PORTA							0
#define MGPIO_PORTB							1
#define MGPIO_PORTC							2
#define MGPIO_PORTD							4



#define MGPIO_PIN00		    0
#define MGPIO_PIN01	      1
#define MGPIO_PIN02       2
#define MGPIO_PIN03       3
#define MGPIO_PIN04       4
#define MGPIO_PIN05       5
#define MGPIO_PIN06       6
#define MGPIO_PIN07       7
#define MGPIO_PIN08       8
#define MGPIO_PIN09       9
#define MGPIO_PIN10       10
#define MGPIO_PIN11       11
#define MGPIO_PIN12       12
#define MGPIO_PIN13       13
#define MGPIO_PIN14       14
#define MGPIO_PIN15       15



//Input modes

#define MGPIO_INPUT_ANALOH					0b0000
#define MGPIO_INPUT_FLOATING				0b0100
#define MGPIO_INPUT_PULLUP_PULLDOWN			0b1000


//output modes


#define MGPIO_OUTPUT_2MHZ_PP				0b0010
#define MGPIO_OUTPUT_2MHZ_OP				0b0110
#define MGPIO_OUTPUT_2MHZ_AFPP				0b1010
#define MGPIO_OUTPUT_2MHZ_AFOP				0b1110

#define MGPIO_OUTPUT_10MHZ_PP				0b0001
#define MGPIO_OUTPUT_10MHZ_OP				0b0101
#define MGPIO_OUTPUT_10MHZ_AFPP				0b1001
#define MGPIO_OUTPUT_10MHZ_AFOP				0b1101

#define MGPIO_OUTPUT_50MHZ_PP				0b0011
#define MGPIO_OUTPUT_50MHZ_OP				0b0111
#define MGPIO_OUTPUT_50MHZ_AFPP				0b1011
#define MGPIO_OUTPUT_50MHZ_AFOP				0b1111

void MGPIO_VidSetPinDirection   (u8 Copy_U8Port  , u8 Copy_U8Pin , u8 Copy_U8Mode);

void MGPIO_VidSetPinValue   (u8 Copy_U8Port  , u8 Copy_U8Pin , u8 Copy_U8Value);

u8 MGPIO_VidGetPinValue   (u8 Copy_U8Port  , u8 Copy_U8Pin );


void MGPIO_VidPortBitSet_BSRR(u8 Copy_U8Port  , u8 Copy_U8PinsNumbre , u8 Copy_U8StartPosition);

void MGPIO_VidPortBitReset_BSRR(u8 Copy_U8Port  , u8 Copy_U8PinsNumbre , u8 Copy_U8StartPosition);








#endif
