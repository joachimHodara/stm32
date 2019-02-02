cmake_minimum_required(VERSION 3.13)

project(miniblink VERSION 1.0
                  DESCRIPTION "Blinking LED on STM32F103C8T6"
                  LANGUAGES CXX)

add_executable(miniblink.elf main.cpp)
target_compile_definitions(miniblink.elf PRIVATE STM32F1)
target_compile_options(miniblink.elf PRIVATE -g -mcpu=cortex-m3 -mthumb)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --static -nostartfiles \
	-T ${PROJECT_SOURCE_DIR}/stm32f103c8t6.ld \
	-Wl,-Map=miniblink.map \
	-Wl,--gc-sections \
	-specs=nosys.specs \
	-Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group")
target_link_libraries(miniblink.elf PRIVATE opencm3_stm32f1)

add_custom_command(
    TARGET miniblink.elf
    COMMAND ${SIZE_COMMAND} miniblink.elf
    COMMAND ${OBJCOPY_COMMAND} -O binary miniblink.elf miniblink.bin
    )
