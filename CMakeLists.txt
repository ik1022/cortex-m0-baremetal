cmake_minimum_required(VERSION 3.31)

# project name
project(baremetal)


#include("cmake/flash.cmake")
#include("cmake/arm-none-eabi.cmake")

# select linker script
set(LINKER_SCRIPT "ld/stm32f031x6.ld")

# define CPU OPTIONS
set(CPU_OPTIONS -mthumb -mcpu=cortex-m0)

# optimizations (-O0 -O1 -O2 -O3 -Os -Ofast -Og -flto)
set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-Os -g -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -g -flto -DNDEBUG")

add_compile_options(
    ${CPU_OPTIONS}
    $<$<COMPILE_LANGUAGE:C>:-std=c11>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    -fstrict-volatile-bitfields
    -ffunction-sections
    -fno-threadsafe-statics

    -Werror
    -Wall
    -Wextra
    -Wcast-align
    -Wconversion
    -Wsign-conversion
    -Wold-style-cast
    -Wshadow
    -Wlogical-op
    -Wsuggest-override
    -Wsuggest-final-types
    -Wsuggest-final-methods
    -pedantic
)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

link_directories(
    ${CMAKE_SOURCE_DIR}
)

# list of modules to build final firmware
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/startup/startup.cpp
    src/startup/stack.cpp
    src/startup/handlers_cm.cpp
    src/startup/handlers_stm32.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${CPU_OPTIONS}
    -T${LINKER_SCRIPT}
    -nostartfiles
    m
    -nostdlib
)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINK_DEPENDS ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT})



function(post_build TARGET)
add_custom_command(
    TARGET ${TARGET}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex ${TARGET} ${TARGET}.hex
    COMMAND ${CMAKE_OBJDUMP} -S ${TARGET} > ${TARGET}.lst
    COMMAND ${CMAKE_NM} -C -l -n -S ${TARGET} > ${TARGET}.sym
    COMMAND arm-none-eabi-size --format=berkeley ${TARGET}
)
endfunction()

post_build(${PROJECT_NAME})
