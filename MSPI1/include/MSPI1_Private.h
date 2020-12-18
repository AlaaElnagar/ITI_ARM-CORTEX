/*
 * MSPI1_Private.h
 *
 *  Created on: Dec 14, 2020
 *      Author: PC
 */

#ifndef MSPI1_PRIVATE_H_
#define MSPI1_PRIVATE_H_


#define MGPIO_PIN4   4
#define MGPIO_PIN15  15

#define MGPIO_PORTA  0




#define MASTER 							1
#define SLAVE							0
#define SPI_ENABLE						1
#define SPI_DISABLE						0

#define CPHA_READ_THEN_WRITE 		    0
#define CPHA_WRITE_THEN_READ  			1



#define CPOL_RISING_LEADING_EDGE         0
#define CPOL_FALLING_LEADING_EDGE        1



#define PRESCALLER_BY_2					0
#define PRESCALLER_BY_4					1
#define PRESCALLER_BY_8					2
#define PRESCALLER_BY_16				3
#define PRESCALLER_BY_32				4
#define PRESCALLER_BY_64				5
#define PRESCALLER_BY_128				6
#define PRESCALLER_BY_256				7


#define FRAME_FORMATE_MSB		    	0
#define FRAME_FORMATE_LSB			    1

/*Bit 9 SSM: Software slave management*/
#define SSM_S_MANGEMENT_HW   				0
#define SSM_S_MANGEMENT_SW      			1

#define SSI_INTERNAL_SS_EN					1
#define SSI_INTERNAL_SS_DIS					0


#define  EIGHT_BIT_FORMAT   0
#define  NINE_BIT_FORMAT	1


#define SSOE_EN						1
#define SSOE_DIS					0


#define TXDMA_ENABLE					1
#define TXDMA_DISABLE			     	0

#define RXDMA_ENABLE					1
#define RXDMA_DISABLE		     		0


#define  MSPI1_INT_RXENE					0
#define  MSPI1_INT_TXEIE					1



typedef struct {

u32 volatile CR1           ;
u32 volatile CR2           ;
u32 volatile SR            ;
u32 volatile DR            ;
u32 volatile CRCPR         ;
u32 volatile RXCRCR        ;
u32 volatile I2SCFGR       ;
u32 volatile I2SPR         ;


}MSPI1_Types;


#define MSPI1         ((volatile MSPI1_Types*) 0x40013000  )








#endif /* MSPI1_PRIVATE_H_ */
