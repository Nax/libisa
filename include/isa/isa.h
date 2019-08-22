/*
 * Copyright (c) 2019, Maxime Bacoux
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ISA_INCLUDED_H
#define ISA_INCLUDED_H 1

#include <stdint.h>

#if defined(__cplusplus)
# define ISA_API extern "C"
#else
# define ISA_API
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
# define ISA_ARCH_X86_64    1
#elif defined(__i386) || defined(_M_IX86)
# define ISA_ARCH_X86_32    1
#endif

#if defined(ISA_ARCH_X86_64) || defined(ISA_ARCH_X86_32)
# define ISA_ARCH_X86       1
#endif

typedef enum {
    ISA_VENDOR_UNKNOWN      = 0,
    ISA_VENDOR_INTEL        = 1,
    ISA_VENDOR_AMD          = 2
} ISA_Vendor;

typedef enum {
    ISA_FEATURE_X86_FPU             =   0,
    ISA_FEATURE_X86_VME             =   1,
    ISA_FEATURE_X86_DE              =   2,
    ISA_FEATURE_X86_PSE             =   3,
    ISA_FEATURE_X86_TSC             =   4,
    ISA_FEATURE_X86_MSR             =   5,
    ISA_FEATURE_X86_PAE             =   6,
    ISA_FEATURE_X86_MCE             =   7,
    ISA_FEATURE_X86_CX8             =   8,
    ISA_FEATURE_X86_APIC            =   9,
    ISA_FEATURE_X86_SEP             =  10,
    ISA_FEATURE_X86_MTRR            =  11,
    ISA_FEATURE_X86_PGE             =  12,
    ISA_FEATURE_X86_MCA             =  13,
    ISA_FEATURE_X86_CMOV            =  14,
    ISA_FEATURE_X86_PAT             =  15,
    ISA_FEATURE_X86_PSE_36          =  16,
    ISA_FEATURE_X86_PSN             =  17,
    ISA_FEATURE_X86_CLFSH           =  18,
    ISA_FEATURE_X86_DS              =  19,
    ISA_FEATURE_X86_ACPI            =  20,
    ISA_FEATURE_X86_MMX             =  21,
    ISA_FEATURE_X86_FXSR            =  22,
    ISA_FEATURE_X86_SSE             =  23,
    ISA_FEATURE_X86_SSE2            =  24,
    ISA_FEATURE_X86_SS              =  25,
    ISA_FEATURE_X86_HTT             =  26,
    ISA_FEATURE_X86_TM              =  27,
    ISA_FEATURE_X86_IA64            =  28,
    ISA_FEATURE_X86_PBE             =  29,
    ISA_FEATURE_X86_SSE3            =  30,
    ISA_FEATURE_X86_PCLMULQDQ       =  31,
    ISA_FEATURE_X86_DTES64          =  32,
    ISA_FEATURE_X86_MONITOR         =  33,
    ISA_FEATURE_X86_DS_CPL          =  34,
    ISA_FEATURE_X86_VMX             =  35,
    ISA_FEATURE_X86_SMX             =  36,
    ISA_FEATURE_X86_EST             =  37,
    ISA_FEATURE_X86_TM2             =  38,
    ISA_FEATURE_X86_SSSE3           =  39,
    ISA_FEATURE_X86_CNXT_ID         =  40,
    ISA_FEATURE_X86_SDBG            =  41,
    ISA_FEATURE_X86_FMA             =  42,
    ISA_FEATURE_X86_CX16            =  43,
    ISA_FEATURE_X86_XTPR            =  44,
    ISA_FEATURE_X86_PDCM            =  45,
    ISA_FEATURE_X86_PCID            =  46,
    ISA_FEATURE_X86_DCA             =  47,
    ISA_FEATURE_X86_SSE4_1          =  48,
    ISA_FEATURE_X86_SSE4_2          =  49,
    ISA_FEATURE_X86_X2APIC          =  50,
    ISA_FEATURE_X86_MOVBE           =  51,
    ISA_FEATURE_X86_POPCNT          =  52,
    ISA_FEATURE_X86_TSC_DEADLINE    =  53,
    ISA_FEATURE_X86_AES             =  54,
    ISA_FEATURE_X86_XSAVE           =  55,
    ISA_FEATURE_X86_OSXSAVE         =  56,
    ISA_FEATURE_X86_AVX             =  57,
    ISA_FEATURE_X86_F16C            =  58,
    ISA_FEATURE_X86_RDRND           =  59,
    ISA_FEATURE_X86_HYPERVISOR      =  60,
    ISA_FEATURE_X86_FSGSBASE        =  61,
    ISA_FEATURE_X86_SGX             =  62,
    ISA_FEATURE_X86_BMI1            =  63,
    ISA_FEATURE_X86_HLE             =  64,
    ISA_FEATURE_X86_AVX2            =  65,
    ISA_FEATURE_X86_SMEP            =  66,
    ISA_FEATURE_X86_BMI2            =  67,
    ISA_FEATURE_X86_ERMS            =  68,
    ISA_FEATURE_X86_INVPCID         =  69,
    ISA_FEATURE_X86_RTM             =  70,
    ISA_FEATURE_X86_PQM             =  71,
    ISA_FEATURE_X86_MPX             =  72,
    ISA_FEATURE_X86_PQE             =  73,
    ISA_FEATURE_X86_AVX512F         =  74,
    ISA_FEATURE_X86_AVX512DQ        =  75,
    ISA_FEATURE_X86_RDSEED          =  76,
    ISA_FEATURE_X86_ADX             =  77,
    ISA_FEATURE_X86_SMAP            =  78,
    ISA_FEATURE_X86_AVX512IFMA      =  79,
    ISA_FEATURE_X86_PCOMMIT         =  80,
    ISA_FEATURE_X86_CLFLUSHOPT      =  81,
    ISA_FEATURE_X86_CLWB            =  82,
    ISA_FEATURE_X86_INTEL_PT        =  83,
    ISA_FEATURE_X86_AVX512PF        =  84,
    ISA_FEATURE_X86_AVX512ER        =  85,
    ISA_FEATURE_X86_AVX512CD        =  86,
    ISA_FEATURE_X86_SHA             =  87,
    ISA_FEATURE_X86_AVX512BW        =  88,
    ISA_FEATURE_X86_AVX512VL        =  89,
    ISA_FEATURE_X86_PREFETCHWT1     =  90,
    ISA_FEATURE_X86_AVX512VBMI      =  91,
    ISA_FEATURE_X86_UMIP            =  92,
    ISA_FEATURE_X86_PKU             =  93,
    ISA_FEATURE_X86_OSPKE           =  94,
    ISA_FEATURE_X86_AVX512VBMI2     =  95,
    ISA_FEATURE_X86_GFNI            =  96,
    ISA_FEATURE_X86_VAES            =  97,
    ISA_FEATURE_X86_VPCLMULQDQ      =  98,
    ISA_FEATURE_X86_AVX512VNNI      =  99,
    ISA_FEATURE_X86_AVX512BITALG    = 100,
    ISA_FEATURE_X86_AVX512VPOPCNTDQ = 101,
    ISA_FEATURE_X86_RSPID           = 102,
    ISA_FEATURE_X86_SGX_LC          = 103,
    ISA_FEATURE_X86_AVX512_4VNNIW   = 104,
    ISA_FEATURE_X86_AVX512_4FMAPS   = 105,
} ISA_Feature;

#if defined(ISA_ARCH_X86)
ISA_API void ISA_Cpuid(uint32_t* ret, uint32_t fn);
ISA_API void ISA_Cpuid2(uint32_t* ret, uint32_t fn, uint32_t subFn);
#endif

ISA_API void ISA_Init(void);

ISA_API ISA_Vendor  ISA_VendorID(void);
ISA_API const char* ISA_VendorName(void);

ISA_API int ISA_CheckFeature(ISA_Feature feature);
ISA_API int ISA_CheckFeatureHw(ISA_Feature feature);

#endif
