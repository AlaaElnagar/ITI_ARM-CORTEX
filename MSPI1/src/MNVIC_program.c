#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MNVIC_interface.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"

void MNVIC_voidInit(void){

	MSCB -> AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

}

void MNVIC_voidSetPrioirty( s8 Copy_u8INTID , u8 Copy_u8Group , u8 Copy_u8Sub ){

	u8 LOC_u8Priority =  Copy_u8Sub | ( Copy_u8Group << ( MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300 ) / 256 ) ;

	if( Copy_u8INTID >= 0 ){//External

		MNVIC -> IPR [ Copy_u8INTID ] = LOC_u8Priority << 4 ;

	}else{//Internal

		if( ( Copy_u8INTID == MNVIC_MEM_MANAGE ) || ( Copy_u8INTID == MNVIC_BUS_FAULT ) || ( Copy_u8INTID == MNVIC_USAGE_FAULT )){

			Copy_u8INTID += 3 ;

			MSCB -> SHPR1 = LOC_u8Priority << ( ( 8 * Copy_u8INTID ) + 4 ) ;

		}else if ( ( Copy_u8INTID == MNVIC_SV_CALL ) ){

			Copy_u8INTID += 7 ;
			MSCB -> SHPR2 = LOC_u8Priority << ( ( 8 * Copy_u8INTID ) + 4 ) ;

		}else{

			Copy_u8INTID += 8 ;
			MSCB -> SHPR3 = LOC_u8Priority << ( ( 8 * Copy_u8INTID ) + 4 ) ;

		}


	}


}

void MNVIC_voidEnablePeri ( u8 Copy_u8INTID ){
	
	MNVIC -> ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;  
	
}
void MNVIC_voidDisablePeri( u8 Copy_u8INTID ){
	
	MNVIC -> ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
	
}

void MNVIC_voidSetPending   ( u8 Copy_u8INTID ){
	
	MNVIC -> ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
	
}
void MNVIC_voidClearPending ( u8 Copy_u8INTID ){
	
	MNVIC -> ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
	
}

u8 MNVIC_u8GetActive ( u8 Copy_u8INTID ){
	
	u8 LOC_u8Result = GET_BIT( MNVIC -> IABR[ Copy_u8INTID / 32 ] , ( Copy_u8INTID % 32 ) );
	return LOC_u8Result ;
	
}
