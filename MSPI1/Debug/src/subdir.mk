################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MGPIO_program.c \
../src/MNVIC_program.c \
../src/MRCC_program.c \
../src/MSPI1_Prog.c \
../src/MSTK_program.c \
../src/main.c 

OBJS += \
./src/MGPIO_program.o \
./src/MNVIC_program.o \
./src/MRCC_program.o \
./src/MSPI1_Prog.o \
./src/MSTK_program.o \
./src/main.o 

C_DEPS += \
./src/MGPIO_program.d \
./src/MNVIC_program.d \
./src/MRCC_program.d \
./src/MSPI1_Prog.d \
./src/MSTK_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


