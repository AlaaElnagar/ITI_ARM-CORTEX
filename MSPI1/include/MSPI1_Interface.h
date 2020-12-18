/*
 * MSPI1_Interface.h
 *
 *  Created on: Dec 14, 2020
 *      Author: PC
 */

#ifndef _MSPI1_INERFACE_H_
#define _MSPI1_INERFACE_H_



#define MASTER				1

#define SLAVE				0





/*Interrupts enable *
 * 		MSPI1_TXEIE	    	 Tx buffer empty interrupt enable
		MSPI1_RXNEIE 		 RX buffer not empty interrupt enable
		MSPI1_ERRIE		     Error interrupt enable
 */


#define MSPI1_TXEIE			    	7
#define MSPI1_RXNEIE 				6
#define MSPI1_ERRIE				    5


/*  Copy_U8FlagName */


#define	 BUSY_FLAG							0
#define	 OVER_RUN_FLAG						1
#define	 MODE_FAULT_FLAG					2
#define  CRC_ERR_FLAG						3
#define  UNDER_RUN_FLAG						4
#define  CHANNEL_SIDE_FLAG					5
#define  TRANSMIT_BUFFER_EMPTY_FLAG			6
#define  RECIEVE_BUFFER_NOT_EMPTY_FLAG		7







void MSPI1_VidIntialize(u8 Copy_U8MS_Select);


void MSPI1_VidClearFlag(u8 Copy_U8FlagName );




u8 MSPI1_U8GetBusyFlag(u8 Copy_U8FlagName );




void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive );


void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) );


















#endif   /* MSPI1_INTERFACE_H_ */

