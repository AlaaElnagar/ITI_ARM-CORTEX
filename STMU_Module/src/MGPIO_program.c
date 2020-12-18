
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"


void MGPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode  ){
	
	switch( Copy_u8Port ){
	
		case MGPIO_PORTA:
		
			if( Copy_u8Pin <= 7 ){
				
				MGPIOA -> CRL &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
				MGPIOA -> CRL |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
				
			}else if( Copy_u8Pin <= 15 ){
				
				Copy_u8Pin -= 8 ;
				
				MGPIOA -> CRH &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
				MGPIOA -> CRH |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
				
			}
		
		break;
		case MGPIO_PORTB:
				
				if( Copy_u8Pin <= 7 ){
				
					MGPIOB -> CRL &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
					MGPIOB -> CRL |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
				
				}else if( Copy_u8Pin <= 15 ){
					
					Copy_u8Pin -= 8 ;
					
					MGPIOB -> CRH &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
					MGPIOB -> CRH |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
					
				}
			
			break;
			case MGPIO_PORTC:
			
				if( Copy_u8Pin <= 7 ){
				
					MGPIOC -> CRL &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
					MGPIOC -> CRL |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
				
				}else if( Copy_u8Pin <= 15 ){
					
					Copy_u8Pin -= 8 ;
					
					MGPIOC -> CRH &= ~( ( 0b1111 )      << ( Copy_u8Pin * 4 ) ) ;
					MGPIOC -> CRH |= (  ( Copy_u8Mode ) << ( Copy_u8Pin * 4 ) ) ;
					
				}
			
			break;
	
	}
	
}


void MGPIO_voidSetPinValue    ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ){
	
	switch( Copy_u8Port ){
		
		case MGPIO_PORTA:
		
			if( Copy_u8Value == MGPIO_HIGH ){
				
				SET_BIT( MGPIOA -> ODR , Copy_u8Pin );
				
			}
			else if(Copy_u8Value == MGPIO_LOW){
				 
				 CLR_BIT( MGPIOA -> ODR , Copy_u8Pin );
				 
			}
			
		break;
		case MGPIO_PORTB:
		
			if( Copy_u8Value == MGPIO_HIGH ){
				
				SET_BIT( MGPIOB -> ODR , Copy_u8Pin );
				
			}
			else if(Copy_u8Value == MGPIO_LOW){
				 
				 CLR_BIT( MGPIOB -> ODR , Copy_u8Pin );
				 
			}
		
		break;
		case MGPIO_PORTC:
		
			if( Copy_u8Value == MGPIO_HIGH ){
				
				SET_BIT( MGPIOC -> ODR , Copy_u8Pin );
				
			}
			else if(Copy_u8Value == MGPIO_LOW){
				 
				 CLR_BIT( MGPIOC -> ODR , Copy_u8Pin );
				 
			}
		
		break;
		
	}
	
}


u8   MGPIO_u8GetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin ){
	
		u8 LOC_u8Result = 0;
	
		switch( Copy_u8Port ){
			
			case MGPIO_PORTA:  LOC_u8Result = GET_BIT( MGPIOA -> IDR , Copy_u8Pin ); break;
			case MGPIO_PORTB:  LOC_u8Result = GET_BIT( MGPIOB -> IDR , Copy_u8Pin ); break;
			case MGPIO_PORTC:  LOC_u8Result = GET_BIT( MGPIOC -> IDR , Copy_u8Pin ); break;
			
		}
		
		return LOC_u8Result ;
	
}
