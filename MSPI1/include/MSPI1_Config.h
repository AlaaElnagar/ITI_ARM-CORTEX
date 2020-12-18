/*
 * MSPI1_Config.h
 *
 *  Created on: Dec 14, 2020
 *      Author: PC
 */

#ifndef _MSPI1_CONFIG_H_
#define _MSPI1_CONFIG_H_


/*
 1- MGPIO_PIN4      						   //SPI1__ NSS PIN >>>incase of  default without remaping


 2- MGPIO_PIN15  							//SPI1__ NSS PIN >>>incase of remaping

*/


#define MSPI1_SLAVE_SELECT_PIN        MGPIO_PIN4


/*  only one selection  MGPIO_PORTA     */


#define MSPI1_SLAVE_SELECT_PORT       MGPIO_PORTA

/*
 SPI_ENABLE
 SPI_DISABLE
*/

#define SPI_CASE      SPI_ENABLE


/*
MASTER
SLAVE	*/

#define MSPI1_MASTER_OR_SLAVE_SELCT        MASTER



/*
		1 -  CPHA_READ_THEN_WRITE
		2 -  CPHA_WRITE_THEN_READ
 */

#define MSPI1_CPHA_SELECT    CPHA_WRITE_THEN_READ
/*
		1 - CPOL_RISING
        2 - CPOL_FALLING
*/

#define MSPI1_CPOL_SELECT   CPOL_RISING_LEADING_EDGE

/*

PRESCALLER_BY_2
PRESCALLER_BY_4
PRESCALLER_BY_8
PRESCALLER_BY_16
PRESCALLER_BY_32
PRESCALLER_BY_64
PRESCALLER_BY_128
PRESCALLER_BY_256
 */

#define MSPI1_PRESCALLER_SELECT	  PRESCALLER_BY_64

/*
FRAME_FORMATE_MSB
FRAME_FORMATE_LSB

*/

#define MSPI1_FRAME_SELECT  FRAME_FORMATE_LSB

/*SSM: Software slave management*/
 /* 1-SSM_S_MANGEMENT_HW					NSS recive  0 from master to be enabled
    2-SSM_S_MANGEMENT_SW					NSS STATE WILL ACTIVATED BY SW according to   MSPI1_SSI_S_SELECTOR
   */

#define MSPI1_SSM_S_SELECTOR        SSM_S_MANGEMENT_HW

//Internal slave select
/* slave can select it self
 *  but SSM_S_SELECTOR must = SSM_S_MANGEMENT_SW
 *  */

//NSS slave select pin for master adnd slave
/*
1 -  SSI_INTERNAL_SS_EN
2 -  SSI_INTERNAL_SS_DIS
*/

#define MSPI1_SSI_S_SELECTOR        SSI_INTERNAL_SS_EN


/*
 * EIGHT_BIT_FORMAT
 * NINE_BIT_FORMAT
 */


#define MSPI1_DATA_FRAME_FORMAT    EIGHT_BIT_FORMAT

//SSOE: SS output enable
//0: SS output is disabled in master mode and the cell can work in multimaster configuration
//1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
//in a multimaster environment.
/*
SS  PIN output enable
1 - SSOE_EN
2 - SSOE_DIS
*/
#define MSPI1_MASTER_M_PIN_STATE		SSOE_EN

/*
1-  TXDMA_ENABLE
2-  TXDMA_DISABLE
  */


#define DMA_TX_STATE			TXDMA_DISABLE
/*
1-  RXDMA_ENABLE
2-  RXDMA_DISABLE
  */

#define DMA_RX_STATE			RXDMA_DISABLE


/*

     //TXEIE: Tx buffer empty interrupt enable

 	 	 1 -  MSPI1_INT_TXEIE

 	// TXEIE: RX buffer not empty interrupt enable

 	 	 2 -  MSPI1_INT_RXENE

 */

#define MSPI1_INT_SATATUS    MSPI1_INT_TXIE


#endif


/* MSPI1_CONFIG_H_ */
