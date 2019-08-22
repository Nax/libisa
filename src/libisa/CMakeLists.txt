# Copyright (c) 2019, Maxime Bacoux
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# All source files
file(GLOB_RECURSE SOURCES "*.c" "*.asm")

# All arch-specific files
file(GLOB_RECURSE SOURCES_ARCH "arch/*")

file(GLOB_RECURSE SOURCES_ARCH_X86 "arch/x86/*")
file(GLOB_RECURSE SOURCES_ARCH_X86_32 "arch/x86_32/*")
file(GLOB_RECURSE SOURCES_ARCH_X86_64 "arch/x86_64/*")

list(REMOVE_ITEM SOURCES ${SOURCES_ARCH})

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86_64)|(X86_64)|(amd64)|(AMD64)")
    list(APPEND SOURCES ${SOURCES_ARCH_X86} ${SOURCES_ARCH_X86_64})
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
    list(APPEND SOURCES ${SOURCES_ARCH_X86} ${SOURCES_ARCH_X86_32})
endif()

add_library(libisa STATIC ${SOURCES})
set_target_properties(libisa PROPERTIES OUTPUT_NAME "isa")
target_include_directories(
    libisa
    PUBLIC  "${CMAKE_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_SOURCE_DIR}/src"
)

install(
    TARGETS libisa
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    DIRECTORY   "${CAMKE_SOURCE_DIR}/include/"
    DESTINATION include
)
