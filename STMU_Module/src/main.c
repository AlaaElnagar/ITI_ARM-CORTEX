/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: PC
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "STMU_interface.h"
u8   Global_U8T1Toggle =1;
u8   Global_U8T2Toggle =1;
u8   Global_U8T3Toggle =1;
void TASK1_VidFunc(){
	Global_U8T1Toggle  ^=1;
	MGPIO_voidSetPinValue    ( MGPIO_PORTC , MGPIO_PIN13, Global_U8T1Toggle );


}
void TASK2_VidFunc(){

	Global_U8T2Toggle  ^=1;
	MGPIO_voidSetPinValue    ( MGPIO_PORTA , MGPIO_PIN0, Global_U8T2Toggle );

}


void TASK3_VidFunc(){

	Global_U8T3Toggle  ^=1;
	MGPIO_voidSetPinValue    ( MGPIO_PORTA , MGPIO_PIN1, Global_U8T3Toggle );

}




int main(){
	Tasks_t TASK1 ,TASK2,TASK3;

	TASK1.Task_Func = TASK1_VidFunc;
	TASK1.Periodicity = 1;
	TASK2.Task_Func = TASK2_VidFunc;
	TASK2.Periodicity = 5;
	TASK3.Task_Func = TASK3_VidFunc;
	TASK3.Periodicity = 10;

	MRCC_voidInitSysClock();//Initialization System Clock Speed 8Mhz Crystel
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN );//Enable GPIOA Peripheral Clock
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );//Enable GPIOA Peripheral Clock

		MGPIO_voidSetPinDirection( MGPIO_PORTC , MGPIO_PIN13, MGPIO_OUTPUT_2MHZ_PP );
		MGPIO_voidSetPinValue    ( MGPIO_PORTC , MGPIO_PIN13, MGPIO_LOW );
		MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN0, MGPIO_OUTPUT_2MHZ_PP );
		MGPIO_voidSetPinValue    ( MGPIO_PORTA , MGPIO_PIN0, MGPIO_LOW );
		MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN1, MGPIO_OUTPUT_2MHZ_PP );
		MGPIO_voidSetPinValue    ( MGPIO_PORTA , MGPIO_PIN1, MGPIO_LOW );

		STMU_VidAddTask(TASK1) ;
	    STMU_VidAddTask(TASK2) ;
	    STMU_VidAddTask(TASK3) ;

		/*This function is responsible for starting TMU scheduler with a specific system tick (from 0 to 16777ms)*/
 	    STMU_VidStartSchudler(100);
while (1);


}
