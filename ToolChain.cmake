set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)

set(OBJCOPY_COMMAND /usr/bin/arm-none-eabi-objcopy)
set(SIZE_COMMAND /usr/bin/arm-none-eabi-size)

set(CMAKE_FIND_ROOT_PATH /usr)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(CMAKE_EXE_LINKER_FLAGS "-nostartfiles")