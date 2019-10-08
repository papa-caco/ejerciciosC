################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bacabaca.c \
../src/cliente.c \
../src/mailsplit.c \
../src/mailsplitter.c \
../src/personas.c \
../src/runner.c \
../src/threadtest1.c 

OBJS += \
./src/bacabaca.o \
./src/cliente.o \
./src/mailsplit.o \
./src/mailsplitter.o \
./src/personas.o \
./src/runner.o \
./src/threadtest1.o 

C_DEPS += \
./src/bacabaca.d \
./src/cliente.d \
./src/mailsplit.d \
./src/mailsplitter.d \
./src/personas.d \
./src/runner.d \
./src/threadtest1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cliente.o: ../src/cliente.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/workspace/tp-2019-2c-No-C-Nada/biblioNOC" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cliente.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


