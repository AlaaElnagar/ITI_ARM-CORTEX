#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "NVIC_interface.h"

#include "NVIC_Private.h"

#include "NVIC_Config.h"



//void MNVIC_VidInit(void);

void MNVIC_VidEnablePrephial(u8 Copy_U8IntID){
	
	MNVIC -> ISER [Copy_U8IntID/32 ]	=	1<<Copy_U8IntID%32;
	
 	
}
void MNVIC_VidDisablePrephial(u8 Copy_U8IntID){
	
		MNVIC -> ICER [Copy_U8IntID/32 ]	=	(0<<(Copy_U8IntID%32));

	
}



void MNVIC_VidSetPending(u8 Copy_U8IntID){
	
		MNVIC -> ISPR [Copy_U8IntID/32 ]	=	1<<Copy_U8IntID%32;

}

void MNVIC_VidClearPending(u8 Copy_U8IntID){
		MNVIC -> ISPR [Copy_U8IntID/32 ]	=	0<<Copy_U8IntID%32;
	
}


u8 MNVIC_U8GetActiveFlag(u8 Copy_U8IntID){
	
	u8 LOC_U8Rsult  = GET_BIT( ((MNVIC ->IABR)[Copy_U8IntID%32]) ,Copy_U8IntID%32)		;

	return   LOC_U8Rsult ;
}
