smptest program

requires following environment valiables to be set:

PICO_SDK_PATH - path to pico sdh folder
FREERTOS_KERNEL_PATH - path to FreeRTOS-Kernel folder
TEST_PATH - path to this application folder
GCC_PATH - path to gcc compiler main folder. This is used only in .vscode settings

Tested:
CMake 3.25.1
arm-none-eabi-gcc 9.2.1
Mac OSX Ventura 13.1
VSCode 

Clone SW:
git clone <tbd>
git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git
cd FreeRTOS-Kernel
git checkout smp
git submodule update --init --recursive

In VSCode
Clean Reconfigure all projects
build
