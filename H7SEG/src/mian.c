/*
 * mian.c
 *
 *  Created on: Dec 11, 2020
 *      Author: PC
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "H7SEG_Interface.h"



int main(){


	MRCC_voidInitSysClock();//Initialization System Clock Speed 8Mhz Crystel
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );//Enable GPIOA Peripheral Clock
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOB_EN );//Enable GPIOA Peripheral Clock
	H7SE_VidIntiate();

	while (1){
for (u32 i =0 ;i<99 ; i++ ){
		 H7SE_VidSnedNumber (i);

}

for (u32 i =99 ;i>0 ; i-- ){
		 H7SE_VidSnedNumber (i);

}

//		 for (u32 j = 0 ; j <250000 ; j++){
//
//		 	asm ("NOP");
//
//		 }
//
//
//}
//
//
//for (u32 i =99 ;i>0 ; i-- ){
//		 H7SE_VidSnedNumber (i);
//
//
//		 for ( u32 j = 0 ; j<250000 ; j++){
//
//		 	asm ("NOP");
//
//		 }
//
//
//}
//
//
//
//
//
//
	}


	}

