#include <stdio.h>
#include <isa/isa.h>

typedef struct {
    ISA_Feature     feature;
    const char*     name;
} NamedFeature;

static const NamedFeature kFeatures[] = {
    { ISA_FEATURE_X86_FPU,               "fpu" },
    { ISA_FEATURE_X86_VME,               "vme" },
    { ISA_FEATURE_X86_DE,                "de" },
    { ISA_FEATURE_X86_PSE,               "pse" },
    { ISA_FEATURE_X86_TSC,               "tsc" },
    { ISA_FEATURE_X86_MSR,               "msr" },
    { ISA_FEATURE_X86_PAE,               "pae" },
    { ISA_FEATURE_X86_MCE,               "mce" },
    { ISA_FEATURE_X86_CX8,               "cx8" },
    { ISA_FEATURE_X86_APIC,              "apic" },
    { ISA_FEATURE_X86_SEP,               "sep" },
    { ISA_FEATURE_X86_MTRR,              "mtrr" },
    { ISA_FEATURE_X86_PGE,               "pge" },
    { ISA_FEATURE_X86_MCA,               "mca" },
    { ISA_FEATURE_X86_CMOV,              "cmov" },
    { ISA_FEATURE_X86_PAT,               "pat" },
    { ISA_FEATURE_X86_PSE_36,            "pse-36" },
    { ISA_FEATURE_X86_PSN,               "psn" },
    { ISA_FEATURE_X86_CLFSH,             "cflsh" },
    { ISA_FEATURE_X86_DS,                "ds" },
    { ISA_FEATURE_X86_ACPI,              "acpi" },
    { ISA_FEATURE_X86_MMX,               "mmx" },
    { ISA_FEATURE_X86_FXSR,              "fxsr" },
    { ISA_FEATURE_X86_SSE,               "sse" },
    { ISA_FEATURE_X86_SSE2,              "sse2" },
    { ISA_FEATURE_X86_SS,                "ss" },
    { ISA_FEATURE_X86_HTT,               "htt" },
    { ISA_FEATURE_X86_TM,                "tm" },
    { ISA_FEATURE_X86_IA64,              "ia64" },
    { ISA_FEATURE_X86_PBE,               "pbe" },
    { ISA_FEATURE_X86_SSE3,              "sse3" },
    { ISA_FEATURE_X86_PCLMULQDQ,         "pcmulqdq" },
    { ISA_FEATURE_X86_DTES64,            "dtes64" },
    { ISA_FEATURE_X86_MONITOR,           "monitor" },
    { ISA_FEATURE_X86_DS_CPL,            "ds-cpl" },
    { ISA_FEATURE_X86_VMX,               "vmx" },
    { ISA_FEATURE_X86_SMX,               "smx" },
    { ISA_FEATURE_X86_EST,               "est" },
    { ISA_FEATURE_X86_TM2,               "tm2" },
    { ISA_FEATURE_X86_SSSE3,             "ssse3" },
    { ISA_FEATURE_X86_CNXT_ID,           "cnxt-id" },
    { ISA_FEATURE_X86_SDBG,              "sdbg" },
    { ISA_FEATURE_X86_FMA,               "fma" },
    { ISA_FEATURE_X86_CX16,              "cx16" },
    { ISA_FEATURE_X86_XTPR,              "xtpr" },
    { ISA_FEATURE_X86_PDCM,              "pdcm" },
    { ISA_FEATURE_X86_PDID,              "pdid" },
    { ISA_FEATURE_X86_DCA,               "dca" },
    { ISA_FEATURE_X86_SSE4_1,            "sse4.1" },
    { ISA_FEATURE_X86_SSE4_2,            "sse4.2" },
    { ISA_FEATURE_X86_X2APIC,            "x2apic" },
    { ISA_FEATURE_X86_MOVBE,             "movbe" },
    { ISA_FEATURE_X86_POPCNT,            "popcnt" },
    { ISA_FEATURE_X86_TSC_DEADLINE,      "tsc-deadline" },
    { ISA_FEATURE_X86_AES,               "aes" },
    { ISA_FEATURE_X86_XSAVE,             "xsave" },
    { ISA_FEATURE_X86_OSXSAVE,           "osxsave" },
    { ISA_FEATURE_X86_AVX,               "avx" },
    { ISA_FEATURE_X86_F16C,              "f16c" },
    { ISA_FEATURE_X86_RDRND,             "rdrnd" },
    { ISA_FEATURE_X86_HYPERVISOR,        "hypervisor" },
    { ISA_FEATURE_X86_FSGSBASE,          "fsgsbase" },
    { ISA_FEATURE_X86_SGX,               "sgx" },
    { ISA_FEATURE_X86_BMI1,              "bmi1" },
    { ISA_FEATURE_X86_HLE,               "hle" },
    { ISA_FEATURE_X86_AVX2,              "avx2" },
    { ISA_FEATURE_X86_SMEP,              "smep" },
    { ISA_FEATURE_X86_BMI2,              "bmi2" },
    { ISA_FEATURE_X86_ERMS,              "erms" },
    { ISA_FEATURE_X86_INVPCID,           "invpcid" },
    { ISA_FEATURE_X86_RTM,               "rtm" },
    { ISA_FEATURE_X86_PQM,               "pqm" },
    { ISA_FEATURE_X86_MPX,               "mpx" },
    { ISA_FEATURE_X86_PQE,               "pqe" },
    { ISA_FEATURE_X86_AVX512F,           "avx512f" },
    { ISA_FEATURE_X86_AVX512DQ,          "avx512dq" },
    { ISA_FEATURE_X86_RDSEED,            "rdseed" },
    { ISA_FEATURE_X86_ADX,               "adx" },
    { ISA_FEATURE_X86_SMAP,              "smap" },
    { ISA_FEATURE_X86_AVX512IFMA,        "avx512ifma" },
    { ISA_FEATURE_X86_PCOMMIT,           "pcommit" },
    { ISA_FEATURE_X86_CLFLUSHOPT,        "clfushopt" },
    { ISA_FEATURE_X86_CLWB,              "clwb" },
    { ISA_FEATURE_X86_INTEL_PT,          "intel_pt" },
    { ISA_FEATURE_X86_AVX512PF,          "avx512pf" },
    { ISA_FEATURE_X86_AVX512ER,          "avx512er" },
    { ISA_FEATURE_X86_AVX512CD,          "avx512cd" },
    { ISA_FEATURE_X86_SHA,               "sha" },
    { ISA_FEATURE_X86_AVX512BW,          "avx512bw" },
    { ISA_FEATURE_X86_AVX512VL,          "avx512vl" },
    { ISA_FEATURE_X86_PREFETCHWT1,       "prefetchwt1" },
    { ISA_FEATURE_X86_AVX512VBMI,        "avx512wbmi" },
    { ISA_FEATURE_X86_UMIP,              "umip" },
    { ISA_FEATURE_X86_PKU,               "pku" },
    { ISA_FEATURE_X86_OSPKE,             "ospke" },
    { ISA_FEATURE_X86_AVX512VBMI2,       "avx512vbmi2" },
    { ISA_FEATURE_X86_GFNI,              "gfni" },
    { ISA_FEATURE_X86_VAES,              "vaes" },
    { ISA_FEATURE_X86_VPCLMULQDQ,        "vpclmulqdq" },
    { ISA_FEATURE_X86_AVX512VNNI,        "avx512vnni" },
    { ISA_FEATURE_X86_AVX512BITALG,      "avx512bitalg" },
    { ISA_FEATURE_X86_AVX512VPOPCNTDQ,   "avx512vpopcntdq" },
    { ISA_FEATURE_X86_RSPID,             "rspid" },
    { ISA_FEATURE_X86_SGX_LC,            "sgx-lc" },
    { ISA_FEATURE_X86_AVX512_4VNNIW,     "avx512_4vnniw" },
    { ISA_FEATURE_X86_AVX512_4FMAPS,     "avx512_4fmaps" },
};

static void printFeature(const NamedFeature* f)
{
    if (ISA_CheckFeature(f->feature))
        printf(" %s", f->name);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    ISA_Init();
    printf("Vendor: %s\n", ISA_VendorName());
    printf("Features:");

    for (size_t i = 0; i < sizeof(kFeatures) / sizeof(*kFeatures); ++i)
        printFeature(&kFeatures[i]);

    printf("\n");
    return 0;
}
