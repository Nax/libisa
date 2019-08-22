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
