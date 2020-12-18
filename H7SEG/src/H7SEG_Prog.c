

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "H7SEG_Private.h"
#include "H7SEG_Interface.h"
#include "H7SEG_Config.h"



void H7SE_VidIntiate(){

#if (  CONTROLLER_SELECT		==		ARM)


	 MGPIO_voidSetPinDirection    (H7SEG_a_PORT	        , H7SEG_a_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_b_PORT	        , H7SEG_b_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_c_PORT	        , H7SEG_c_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_d_PORT	        , H7SEG_d_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_e_PORT	        , H7SEG_e_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_f_PORT	        , H7SEG_f_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_g_PORT	        , H7SEG_g_PIN		         ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_dp_PORT        , H7SEG_dp_PIN	             ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_1_CONTROL_PORT , H7SEG_1_CONTROL_PIN	     ,  H7SEG_OUTPUT_MODE );
	 MGPIO_voidSetPinDirection    (H7SEG_2_CONTROL_PORT , H7SEG_2_CONTROL_PIN	     ,  H7SEG_OUTPUT_MODE );

#elif (#define CONTROLLER_SELECT  ==   AVR)




#endif
}


void H7SE_VidSetNumber(u8 Copy_U8Number ){


MGPIO_voidSetPinValue    (H7SEG_a_PORT	        ,  H7SEG_a_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][0]);
MGPIO_voidSetPinValue    (H7SEG_b_PORT	        ,  H7SEG_b_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][1]);
MGPIO_voidSetPinValue    (H7SEG_c_PORT	        ,  H7SEG_c_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][2]);
MGPIO_voidSetPinValue    (H7SEG_d_PORT	        ,  H7SEG_d_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][3]);
MGPIO_voidSetPinValue    (H7SEG_e_PORT	        ,  H7SEG_e_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][4]);
MGPIO_voidSetPinValue    (H7SEG_f_PORT	        ,  H7SEG_f_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][5]);
MGPIO_voidSetPinValue    (H7SEG_g_PORT	        ,  H7SEG_g_PIN		     , Local_ArrPinstate_cc[Copy_U8Number][6]);
MGPIO_voidSetPinValue    (H7SEG_dp_PORT	        ,  H7SEG_dp_PIN	         , Local_ArrPinstate_cc[Copy_U8Number][7]);



}

u8 flag=0;
void  H7SE_VidSnedNumber (u8 Copy_U8Number){

	/*FIRST 7 SEG*/
	u64 i = 0 ;
	u32 x =0;
	for ( x = 0 ; x <40 ; x++){
if (flag==0){
		MGPIO_voidSetPinValue    (H7SEG_1_CONTROL_PORT , H7SEG_1_CONTROL_PIN	     ,  MGPIO_HIGH );
		MGPIO_voidSetPinValue    (H7SEG_2_CONTROL_PORT , H7SEG_2_CONTROL_PIN	     ,  MGPIO_LOW );

		H7SE_VidSetNumber(Copy_U8Number%10);





for ( i = 0 ; i <5000 ; i++){

	asm ("NOP");

}
flag=1;
}

else{

MGPIO_voidSetPinValue    (H7SEG_1_CONTROL_PORT , H7SEG_1_CONTROL_PIN	     ,  PIN_LOW );
MGPIO_voidSetPinValue    (H7SEG_2_CONTROL_PORT , H7SEG_2_CONTROL_PIN	     ,  PIN_HIGH );
H7SE_VidSetNumber(Copy_U8Number/10);
flag=0;



for ( i = 0 ; i <5000 ; i++){

	asm ("NOP");

}


}

}




}





