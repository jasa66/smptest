cmake_minimum_required(VERSION 3.13)

message("Compiling/Configuring smptest:")
if(DEFINED ENV{TEST_PATH})
    message("Using TEST_PATH from environment: " $ENV{TEST_PATH})
    include(pico_sdk_import.cmake)
    include(FreeRTOS_Kernel_import.cmake)

    project(smptest C CXX ASM)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)

    pico_sdk_init()

    add_executable(smptest
        main.c 
    )

    target_include_directories(smptest PRIVATE 
                            $ENV{TEST_PATH}/../FreeRTOS-Kernel/include   
                            $ENV{TEST_PATH}/FreeRTOSConfig
                            $ENV{TEST_PATH}/inc
                            )

    target_link_libraries(smptest FreeRTOS-Kernel FreeRTOS-Kernel-Heap4 pico_stdlib pico_multicore)

    pico_add_extra_outputs(smptest)

    add_custom_command(TARGET smptest
            POST_BUILD 
            COMMAND arm-none-eabi-size smptest.elf
            )
else()
    message("!!!!!!  TEST_PATH not defined. Please export TEST_PATH environment variable. smptest not build !!!!!")
endif()