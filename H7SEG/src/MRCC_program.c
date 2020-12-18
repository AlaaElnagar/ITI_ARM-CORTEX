
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"


void MRCC_voidInitSysClock(void){
	
	#if MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
	
		//Select HSE
		MRCC -> CFGR = 0x00000001 ;
		//Enable
		MRCC -> CR   = 0x00010080 ;
		//Wait Untill HSE Stable
		while( GET_BIT(MRCC -> CR , 17) == 0 );
	
	#elif MRCC_CLOCK_TYPE == MRCC_HSE_RC
	
		//Select HSE
		MRCC -> CFGR = 0x00000001 ;
		//Enable
		MRCC -> CR   = 0x00050080 ;
		//Wait Untill HSE Stable
		while( GET_BIT(MRCC -> CR , 17) == 0 );
	
	#elif MRCC_CLOCK_TYPE == MRCC_HSI
	
		//Select HSI
		MRCC -> CFGR = 0x00000000 ;
		//Enable
		MRCC -> CR   = 0x00000081 ;
		//Wait Untill HSI Stable
		while( GET_BIT(MRCC -> CR , 1) == 0 );
		
	#elif MRCC_CLOCK_TYPE == MRCC_PLL
	
		MRCC -> CFGR = 0x00000000 ;
		MRCC -> CR   = 0x00000081 ;
		
		//Select PLL
		MRCC -> CFGR = 0x00000002 ;
		
		#if( MRCC_PLL_MUL_VAL >= MRCC_PLL_MUL_BY_2 ) && ( MRCC_PLL_MUL_VAL <= MRCC_PLL_MUL_BY_16 )
			
			MRCC -> CFGR &= ~((0b1111) << 18 ) ;
			MRCC -> CFGR |= ((MRCC_PLL_MUL_VAL) << 18 ) ;
			
		#else 
			#warning ("Wrong Multiplication Factor For PLL")
		#endif 
		
		#if MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_2
			
			CLR_BIT( MRCC -> CFGR , 16 );
			
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_2
			
			SET_BIT( MRCC -> CR , 16 );
			
			SET_BIT( MRCC -> CFGR , 16 );
			SET_BIT( MRCC -> CFGR , 17 );
			
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE

			SET_BIT( MRCC -> CR , 16 );
			
			SET_BIT( MRCC -> CFGR , 16 );
			CLR_BIT( MRCC -> CFGR , 17 );
		
		#endif 
		
		SET_BIT( MRCC -> CR , 24 );
		while( GET_BIT( MRCC -> CR , 25 ) == 0 );
	
	#endif 
	
	#if   MRCC_CS_SYS == MRCC_ENABLE_CS
	
		SET_BIT( MRCC -> CR , 19 );
		
	#elif   MRCC_CS_SYS == MRCC_DISABLE_CS
	
		CLR_BIT( MRCC -> CR , 19 );
		
	#endif
	
}


void MRCC_voidEnablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId ){
	
	switch( Copy_u8BusId ){
		
		case MRCC_AHB   : SET_BIT( MRCC -> AHBENR  , Copy_u8PerId  );  break;
		case MRCC_APB1  : SET_BIT( MRCC -> APB1ENR , Copy_u8PerId ) ;  break;
	    case MRCC_APB2  : SET_BIT( MRCC -> APB2ENR , Copy_u8PerId ) ;  break;
		
	}
	
}

void MRCC_voidDisablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId ){
	
	switch( Copy_u8BusId ){
		
		case MRCC_AHB   : CLR_BIT( MRCC -> AHBENR  , Copy_u8PerId  );  break;
		case MRCC_APB1  : CLR_BIT( MRCC -> APB1ENR , Copy_u8PerId );  break;
	    case MRCC_APB2  : CLR_BIT( MRCC -> APB2ENR , Copy_u8PerId );  break;
		
	}
	
}


