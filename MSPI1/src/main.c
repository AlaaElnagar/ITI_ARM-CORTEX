/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: Alaa Elnagar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "MSPI1_interface.h"
#include "MNVIC_interface.h"
#include "MSTK_interface.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

/*Global recive data incase of sync or async*/
u8 Global = 0 ;

void MSPI_VidSendReciveData(u8 Data){
	Global = Data ;

}




/****************************CODE SWITCHING **********************************/
/*
		1 - MASTER
		2 - SLAVE
 */

//dont forget to stup the configration as master or slave

#define CODE_FLASH_MODE			MASTER




/*****************************************************************************/


#if CODE_FLASH_MODE ==MASTER



void main(void){
	MRCC_voidInitSysClock  ();

	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN );
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_SPI1_EN  );

	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN5 , MGPIO_OUTPUT_2MHZ_AFPP ); /* CLK  */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN6 , MGPIO_INPUT_FLOATING   ); /* MISO */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN7 , MGPIO_OUTPUT_2MHZ_AFPP ); /* MOSI */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN4 , MGPIO_OUTPUT_2MHZ_PP   ); /* SS   */
	//MGPIO_voidSetPinValue( MGPIO_PORTA , MGPIOPIN4 , MGPIO_HIGH   ); /* SS   */

	//MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN4 , MGPIO_OUTPUT_2MHZ_AFPP   ); /* SS   */

	MSTK_voidInit();
    MSPI1_VidIntialize(MASTER);

	while(1){

		//    MSPI1_voidSendReceiveAsynch ( 5 ,MSPI_VidSendReciveData(10));
		MSPI1_voidSendReceiveSynch( 12  , &Global );
		MSTK_voidSetBusyWait(1000000);
		//    MSPI1_voidSendReceiveAsynch ( 20 ,MSPI_VidSendReciveData(10));

		MSPI1_voidSendReceiveSynch( 17 , &Global );
		MSTK_voidSetBusyWait(1000000);



}


}


#elif CODE_FLASH_MODE ==SLAVE

void main(void){
	MRCC_voidInitSysClock  ();

	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_SPI1_EN  );

	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN5 , MGPIO_INPUT_FLOATING );   /* CLK  */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN6 , MGPIO_OUTPUT_2MHZ_AFPP);  /* MISO */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN7 , MGPIO_INPUT_FLOATING );   /* MOSI */
	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN4 , MGPIO_INPUT_FLOATING );   /* SS   */

	MSTK_voidInit();
    MSPI1_VidIntialize(SLAVE);

	while(1){

		//    MSPI1_voidSendReceiveAsynch ( 5 ,MSPI_VidSendReciveData(10));
		MSPI1_voidSendReceiveSynch( 12  , &Global );

	}


}

#endif
