cmake_minimum_required(VERSION 3.16)
project(libc VERSION 0.1)
enable_language(C ASM)

# You can pass -DTARGET_ARCH=<arch> to select an architecture
if(NOT DEFINED TARGET_ARCH)
    set(TARGET_ARCH "x86_64") # Default architecture
endif()

include(${TARGET_ARCH}.cmake OPTIONAL)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Generic")
message(FATAL_ERROR "Please specify a compatible toolchain file. 
For example: \"cmake -DCMAKE_TOOLCHAIN_FILE=../x64.cmake ..\"")
endif()

add_library(c_core
    src/errno.c
    src/malloc.c
    src/string.c
)

add_library(c
    src/init.c
    ${ARCH_SOURCES}
)

target_compile_options(c_core PRIVATE 
    -Wall -Wextra -pedantic -Werror
    -ffreestanding
    -fshort-wchar
    -mno-red-zone
    -Wno-unused-variable
    -Wno-unused-command-line-argument
    -Wno-c11-extensions
    -Wno-c99-extensions
    -Wno-c2x-extensions
    -Wno-language-extension-token
    -Wno-writable-strings)

target_compile_options(c PRIVATE 
    -Wall -Wextra -pedantic -Werror
    -ffreestanding
    -fshort-wchar
    -mno-red-zone
    -Wno-unused-variable
    -Wno-unused-command-line-argument
    -Wno-c11-extensions
    -Wno-c99-extensions
    -Wno-c2x-extensions
    -Wno-language-extension-token
    -Wno-writable-strings)

target_link_options(c_core PRIVATE
    -nostdlib)

target_link_options(c PRIVATE
    -nostdlib)

target_link_libraries(c PRIVATE
    c_core erikbus)

target_include_directories(c_core PUBLIC 
    include)

target_include_directories(c PUBLIC 
    include)

install(TARGETS c_core c)
