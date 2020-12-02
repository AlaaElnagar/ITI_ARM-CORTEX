/*
 * main.c
 *
 *  Created on: 2/12/2020
 *      Author: Alaa Elanagar
        Mobile:+201019793647
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"




void main(void){
	/*sys clock initialization speed of  8 mhz and crystal */
	 MRCC_VidInitSysClock ();
	 /*enable gpio a prephial clck*/
	MRCC_VidEnablePeriClock(MRCC_APB2,MRCC_GPIOA_EN);


MGPIO_VidSetPinDirection   (  MGPIO_PORTA	 ,  MGPIO_PIN00 , MGPIO_OUTPUT_2MHZ_PP);

 MGPIO_VidSetPinValue   ( MGPIO_PORTA  ,  MGPIO_PIN00 , MGPIO_HIGH);

 MGPIO_VidSetPinDirection   (  MGPIO_PORTA	 ,  MGPIO_PIN01 , MGPIO_OUTPUT_2MHZ_PP);

  MGPIO_VidSetPinValue   ( MGPIO_PORTA  ,  MGPIO_PIN01 , MGPIO_HIGH);

 //MGPIO_VidGetPinValue   (u8 Copy_U8Port  , u8 Copy_U8Pin );

	while (1);



}
