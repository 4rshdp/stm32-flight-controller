################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Commuication/flysky.c \
../Core/Src/Commuication/ibus.c 

OBJS += \
./Core/Src/Commuication/flysky.o \
./Core/Src/Commuication/ibus.o 

C_DEPS += \
./Core/Src/Commuication/flysky.d \
./Core/Src/Commuication/ibus.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Commuication/%.o Core/Src/Commuication/%.su Core/Src/Commuication/%.cyclo: ../Core/Src/Commuication/%.c Core/Src/Commuication/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Communication" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/ControlAlgorithm" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Flight" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/SensorFusion" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Monitoring" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Monitoring" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Commuication

clean-Core-2f-Src-2f-Commuication:
	-$(RM) ./Core/Src/Commuication/flysky.cyclo ./Core/Src/Commuication/flysky.d ./Core/Src/Commuication/flysky.o ./Core/Src/Commuication/flysky.su ./Core/Src/Commuication/ibus.cyclo ./Core/Src/Commuication/ibus.d ./Core/Src/Commuication/ibus.o ./Core/Src/Commuication/ibus.su

.PHONY: clean-Core-2f-Src-2f-Commuication

