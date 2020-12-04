#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "NVIC_Interface.h"





void EXTI0_IRQHandler(void ){

	 MGPIO_VidSetPinValue   ( MGPIO_PORTA  ,  MGPIO_PIN00 , MGPIO_HIGH);

}


int main (){

	 MRCC_VidInitSysClock ();
	 /*enable gpio a prephial clck*/
    MRCC_VidEnablePeriClock(MRCC_APB2,MRCC_GPIOA_EN);

	MGPIO_VidSetPinDirection   (  MGPIO_PORTA	 ,  MGPIO_PIN00 , MGPIO_OUTPUT_2MHZ_PP);

	 MGPIO_VidSetPinValue   ( MGPIO_PORTA  ,  MGPIO_PIN00 , MGPIO_LOW);


	MNVIC_VidEnablePrephial(6);
	MNVIC_VidSetPending(6);

	while (1);
}
