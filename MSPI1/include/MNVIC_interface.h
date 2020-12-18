#ifndef _MNVIC_INTERFACE_H_
#define _MNVIC_INTERFACE_H_






#define MNVIC_PEND_SV      -6
#define MNVIC_SYSTICK      -5

#define MNVIC_SV_CALL      -4

#define MNVIC_MEM_MANAGE   -3
#define MNVIC_BUS_FAULT    -2
#define MNVIC_USAGE_FAULT  -1


#define MNVIC_EXTI0_IRQ     6


void MNVIC_voidInit(void);

void MNVIC_voidSetPrioirty( s8 Copy_u8INTID , u8 Copy_u8Group , u8 Copy_u8Sub );

void MNVIC_voidEnablePeri ( u8 Copy_u8INTID );
void MNVIC_voidDisablePeri( u8 Copy_u8INTID );

void MNVIC_voidSetPending   ( u8 Copy_u8INTID );
void MNVIC_voidClearPending ( u8 Copy_u8INTID );

u8 MNVIC_u8GetActive ( u8 Copy_u8INTID );


#endif
