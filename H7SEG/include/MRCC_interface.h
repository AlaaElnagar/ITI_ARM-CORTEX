

#ifndef _MRCC_INTERFACE_
#define _MRCC_INTERFACE_

#define MRCC_AHB    0
#define MRCC_APB1   1
#define MRCC_APB2   2

/* AHB */

/* APB2 */

#define MRCC_GPIOA_EN  2
#define MRCC_GPIOB_EN  3
#define MRCC_GPIOC_EN  4
#define MRCC_AFIO_EN   0


#define MRCC_DMA1_EN   0

/* APB1 */

void MRCC_voidInitSysClock(void);


void MRCC_voidEnablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId );

void MRCC_voidDisablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId );

#endif 
