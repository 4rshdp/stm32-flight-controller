################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Flight/calibration.c \
../Core/Src/Flight/flight_manager.c \
../Core/Src/Flight/motor_control.c 

OBJS += \
./Core/Src/Flight/calibration.o \
./Core/Src/Flight/flight_manager.o \
./Core/Src/Flight/motor_control.o 

C_DEPS += \
./Core/Src/Flight/calibration.d \
./Core/Src/Flight/flight_manager.d \
./Core/Src/Flight/motor_control.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Flight/%.o Core/Src/Flight/%.su Core/Src/Flight/%.cyclo: ../Core/Src/Flight/%.c Core/Src/Flight/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Communication" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/ControlAlgorithm" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Flight" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/SensorFusion" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Monitoring" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Monitoring" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Flight

clean-Core-2f-Src-2f-Flight:
	-$(RM) ./Core/Src/Flight/calibration.cyclo ./Core/Src/Flight/calibration.d ./Core/Src/Flight/calibration.o ./Core/Src/Flight/calibration.su ./Core/Src/Flight/flight_manager.cyclo ./Core/Src/Flight/flight_manager.d ./Core/Src/Flight/flight_manager.o ./Core/Src/Flight/flight_manager.su ./Core/Src/Flight/motor_control.cyclo ./Core/Src/Flight/motor_control.d ./Core/Src/Flight/motor_control.o ./Core/Src/Flight/motor_control.su

.PHONY: clean-Core-2f-Src-2f-Flight

