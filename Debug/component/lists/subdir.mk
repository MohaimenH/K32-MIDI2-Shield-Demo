################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/lists/fsl_component_generic_list.c 

C_DEPS += \
./component/lists/fsl_component_generic_list.d 

OBJS += \
./component/lists/fsl_component_generic_list.o 


# Each subdirectory must supply rules for building sources it contributes
component/lists/%.o: ../component/lists/%.c component/lists/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_K32L2B31VLH0A -DCPU_K32L2B31VLH0A_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/board" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/tinyusb-midi2/src" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/tinyusb-midi2" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/source" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/drivers" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/serial_manager" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/CMSIS" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/device" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/lists" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/uart" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-lists

clean-component-2f-lists:
	-$(RM) ./component/lists/fsl_component_generic_list.d ./component/lists/fsl_component_generic_list.o

.PHONY: clean-component-2f-lists

