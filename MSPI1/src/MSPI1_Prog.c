/*
 * MSPI1_Prog.c
 *
 *  Created on: Dec 14, 2020
 *      Author: PC
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSPI1_Private.h"
#include "MSPI1_Config.h"
#include "MSPI1_Interface.h"
#include "MGPIO_interface.h"
#include "MRCC_interface.h"

static void (*MSPI_CallBack)(u8 Data);


void MSPI1_VidIntialize(u8 Copy_U8MS_Select){

#if SPI_CASE == SPI_ENABLE

	/*****************************CLK Phase***********************************/
	MSPI1 -> CR1 |=    MSPI1_CPHA_SELECT << 0  ;
	/*****************************CLK Polarity***********************************/

	MSPI1 -> CR1 |=    MSPI1_CPOL_SELECT << 1  ;


	/****************************Data Order  LSB OR MSB************************************/
	MSPI1 -> CR1 |=   MSPI1_FRAME_SELECT << 7 ;
	/***************************8BIT FRAME OR 9 BIT *************************************/
	MSPI1 -> CR1 |=   MSPI1_DATA_FRAME_FORMAT << 11 ;


if   (Copy_U8MS_Select == MASTER) {


/*****************************Master select ***********************************/

	MSPI1 -> CR1 |=    MASTER  << 2  ;


/*************************NSS SOFTWARE SLAVE MANGEMENT DISABLED */
	MSPI1 -> CR1 |=  0 << 9 ;
	MSPI1 -> CR1 |=  0 << 8 ;

/*CR2 regester operations */
MSPI1 -> CR2 |=    MSPI1_MASTER_M_PIN_STATE<<2;
/*********************************DMA DATA copy*********************************************/
MSPI1 -> CR2 |=    DMA_TX_STATE << 1					;
MSPI1 -> CR2 |=    DMA_RX_STATE << 0					;
/**************************SS Pin in master manged by hardware or sw *************************************/
MSPI1 -> CR2 |=    MSPI1_MASTER_M_PIN_STATE << 2		;



/*************************** CLK Rate Selection **********************/

MSPI1 -> CR1 |= (MSPI1_PRESCALLER_SELECT<< 3) ;
MSPI1 -> CR1 |=  SPI_ENABLE << 6 ;


}
else if ( Copy_U8MS_Select == SLAVE ) {
	/*****************************slave select ***********************************/
		MSPI1 -> CR1 |=    SLAVE  << 2  ;
    /******************************NSS Enabled according to master signal ******************************/
#if  MSPI1_SSM_S_SELECTOR   ==  SSM_S_MANGEMENT_HW
		MSPI1 -> CR1 |=   SSM_S_MANGEMENT_HW << 9 ;
		/*Internal slave select*/
		MSPI1 -> CR1 |=  SSI_INTERNAL_SS_EN << 8 ;

/******************************NSS Enabled according to SW ******************************/
#elif MSPI1_SSM_S_SELECTOR   == SSM_S_MANGEMENT_SW
		MSPI1 -> CR1 =  SSM_S_MANGEMENT_HW << 9 ;
		/*Internal slave select*/
		MSPI1 -> CR1 =  SSI_INTERNAL_SS_DIS << 8 ;
#else

#warning ("warrning SSM_S_SELECTOR not defined")

#endif




}



#elif 	MSPI1_SPI_CASE == DISABLE
MSPI1 -> CR1 |=  SPI_DISABLE << 6 ;

#else

#warning ("warrning SPI_CASE not defined ")

#endif




}



void MSPI1_VidClearFlag(u8 Copy_U8FlagName ){


	if (Copy_U8FlagName == BUSY_FLAG ){
	}


	else if (Copy_U8FlagName == OVER_RUN_FLAG){


	}

	else if  (Copy_U8FlagName == MODE_FAULT_FLAG){

	}


}


u8 MSPI1_U8GetBusyFlag(u8 Copy_U8FlagName ){

if (Copy_U8FlagName == BUSY_FLAG ){
return (GET_BIT(MSPI1 -> SR,7));
}


else if (Copy_U8FlagName == OVER_RUN_FLAG){

return (GET_BIT(MSPI1 -> SR,6));

}

else if  (Copy_U8FlagName == MODE_FAULT_FLAG){
return (GET_BIT(MSPI1 -> SR,5));

}

else if  (Copy_U8FlagName == CRC_ERR_FLAG){
return (GET_BIT(MSPI1 -> SR,4));

}

else if  (Copy_U8FlagName == UNDER_RUN_FLAG){
return (GET_BIT(MSPI1 -> SR,3));

}

else
	return (5);
}




void MSPI1_VidDisableSPI(){



}







void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive ){

	/* Disable All Interrupts */
	//MSPI1 -> CR2 = 0 ;

	MGPIO_voidSetPinValue( MSPI1_SLAVE_SELECT_PORT, MSPI1_SLAVE_SELECT_PIN , MGPIO_LOW  );

	MSPI1 -> DR = Copy_u8Data ;

	while( GET_BIT( MSPI1 -> SR , 7 ) == 1 );

	*Copy_ptrDataToReceive = MSPI1 -> DR ;

	MGPIO_voidSetPinValue(MSPI1_SLAVE_SELECT_PORT, MSPI1_SLAVE_SELECT_PIN , MGPIO_HIGH );


}

void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) ){

	MSPI1 -> DR = Copy_u8Data ;

	MSPI_CallBack = Copy_CallBack ;

	#if     MSPI1_INT_SATATUS == MSPI1_INT_TXIE

		SET_BIT( MSPI1 -> CR2 , 7 );

	#elif   MSPI1_INT_SATATUS == MSPI1_INT_RXENE

		SET_BIT( MSPI1 -> CR2 , 6 );

	#endif

}


void MSPI1_IRQHandler(void){

	MSPI_CallBack( MSPI1 -> DR );

}


