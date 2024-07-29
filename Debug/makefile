################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include tinyusb-midi2/src/typec/subdir.mk
-include tinyusb-midi2/src/portable/nxp/lpc_ip3511/subdir.mk
-include tinyusb-midi2/src/portable/nxp/lpc17_40/subdir.mk
-include tinyusb-midi2/src/portable/nxp/khci/subdir.mk
-include tinyusb-midi2/src/host/subdir.mk
-include tinyusb-midi2/src/device/subdir.mk
-include tinyusb-midi2/src/common/subdir.mk
-include tinyusb-midi2/src/class/video/subdir.mk
-include tinyusb-midi2/src/class/vendor/subdir.mk
-include tinyusb-midi2/src/class/usbtmc/subdir.mk
-include tinyusb-midi2/src/class/net/subdir.mk
-include tinyusb-midi2/src/class/msc/subdir.mk
-include tinyusb-midi2/src/class/midi/subdir.mk
-include tinyusb-midi2/src/class/hid/subdir.mk
-include tinyusb-midi2/src/class/dfu/subdir.mk
-include tinyusb-midi2/src/class/cdc/subdir.mk
-include tinyusb-midi2/src/class/bth/subdir.mk
-include tinyusb-midi2/src/class/audio/subdir.mk
-include tinyusb-midi2/src/subdir.mk
-include startup/subdir.mk
-include source/bsp/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := K32L2B31A_Project_MIDI2_Shield_Demo
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: K32L2B31A_Project_MIDI2_Shield_Demo.axf

# Tool invocations
K32L2B31A_Project_MIDI2_Shield_Demo.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="K32L2B31A_Project_MIDI2_Shield_Demo.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T K32L2B31A_Project_MIDI2_Shield_Demo_Debug.ld -o "K32L2B31A_Project_MIDI2_Shield_Demo.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) K32L2B31A_Project_MIDI2_Shield_Demo.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "K32L2B31A_Project_MIDI2_Shield_Demo.axf"; # arm-none-eabi-objcopy -v -O binary "K32L2B31A_Project_MIDI2_Shield_Demo.axf" "K32L2B31A_Project_MIDI2_Shield_Demo.bin" ; # checksum -p K32L2B31xxxxA -d "K32L2B31A_Project_MIDI2_Shield_Demo.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
