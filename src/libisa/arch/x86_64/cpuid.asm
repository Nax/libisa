; Copyright (c) 2019, Maxime Bacoux
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are met:
;
; 1. Redistributions of source code must retain the above copyright notice, this
;    list of conditions and the following disclaimer.
;
; 2. Redistributions in binary form must reproduce the above copyright notice,
;    this list of conditions and the following disclaimer in the documentation
;    and/or other materials provided with the distribution.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
; CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
; OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

BITS 64

%ifidn __OUTPUT_FORMAT__, win64
%define ARG0   rcx
%define ARG1   edx
%define ARG2   r8d
%else
%define ARG0   rdi
%define ARG1   esi
%define ARG2   edx
%define ISA_Cpuid2 _ISA_Cpuid2
%endif

SECTION .text
ALIGN 16
GLOBAL ISA_Cpuid2

ISA_Cpuid2:
    push rbx

    mov r11, ARG0
    mov eax, ARG1
    mov ecx, ARG2

    cpuid

    mov DWORD [r11 + 0x00], eax
    mov DWORD [r11 + 0x04], ebx
    mov DWORD [r11 + 0x08], ecx
    mov DWORD [r11 + 0x0c], edx

    pop rbx
    ret
