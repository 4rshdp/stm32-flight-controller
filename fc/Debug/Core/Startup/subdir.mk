################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f405rgtx.s 

OBJS += \
./Core/Startup/startup_stm32f405rgtx.o 

S_DEPS += \
./Core/Startup/startup_stm32f405rgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Driver" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Communication" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/ControlAlgorithm" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Flight" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/SensorFusion" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Inc/Monitoring" -I"C:/Users/arshd/Desktop/Workspace/RedSens/proj/frmskysens/fc/Core/Src/Monitoring" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f405rgtx.d ./Core/Startup/startup_stm32f405rgtx.o

.PHONY: clean-Core-2f-Startup

