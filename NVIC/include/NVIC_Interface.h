#ifndef   _NVIC_INTERFACE_H_
#define   _NVIC_INTERFACE_H_



void MNVIC_VidInit(void);
void MNVIC_VidEnablePrephial(u8 Copy_U8IntID);
void MNVIC_VidDisablePrephial(u8 Copy_U8IntID);



void MNVIC_VidSetPending(u8 Copy_U8IntID);

void MNVIC_VidClearPending(u8 Copy_U8IntID);

u8 MNVIC_U8GetActiveFlag(u8 Copy_U8IntID);
















#endif
