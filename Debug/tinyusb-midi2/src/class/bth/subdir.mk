################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tinyusb-midi2/src/class/bth/bth_device.c 

C_DEPS += \
./tinyusb-midi2/src/class/bth/bth_device.d 

OBJS += \
./tinyusb-midi2/src/class/bth/bth_device.o 


# Each subdirectory must supply rules for building sources it contributes
tinyusb-midi2/src/class/bth/%.o: ../tinyusb-midi2/src/class/bth/%.c tinyusb-midi2/src/class/bth/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_K32L2B31VLH0A -DCPU_K32L2B31VLH0A_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/board" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/tinyusb-midi2/src" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/tinyusb-midi2" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/source" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/drivers" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/serial_manager" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/CMSIS" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/device" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/lists" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/component/uart" -I"/Users/mohaimen/Documents/MCUXpressoIDE_11.10.0_3148/workspace/K32L2B31A_Project_MIDI2_Shield_Demo/utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tinyusb-2d-midi2-2f-src-2f-class-2f-bth

clean-tinyusb-2d-midi2-2f-src-2f-class-2f-bth:
	-$(RM) ./tinyusb-midi2/src/class/bth/bth_device.d ./tinyusb-midi2/src/class/bth/bth_device.o

.PHONY: clean-tinyusb-2d-midi2-2f-src-2f-class-2f-bth

