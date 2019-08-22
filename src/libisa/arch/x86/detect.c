#include <string.h>
#include <libisa/libisa.h>

#define FEATURE(reg, bit, feature) if (info[reg] & (1 << bit)) ISA_SetFeature(feature)

static void ISA_DetectVendor(void)
{
    if (memcmp(ISA_Ctx.vendorName, "GenuineIntel", 12) == 0)
        ISA_Ctx.vendorId = ISA_VENDOR_INTEL;
    else if (memcmp(ISA_Ctx.vendorName, "AuthenticAMD", 12) == 0)
        ISA_Ctx.vendorId = ISA_VENDOR_AMD;
    else if (memcmp(ISA_Ctx.vendorName, "AMDisbetter!", 12) == 0)
        ISA_Ctx.vendorId = ISA_VENDOR_AMD;
    else
        ISA_Ctx.vendorId = ISA_VENDOR_UNKNOWN;
}

ISA_API void ISA_Detect(void)
{
    uint32_t maxFn;
    uint32_t info[4];

    /* CPUID 0 : Max CPUID & Vendor */
    ISA_Cpuid(info, 0);
    maxFn = info[0];
    memcpy(&ISA_Ctx.vendorName[0], &info[1], 4);
    memcpy(&ISA_Ctx.vendorName[4], &info[3], 4);
    memcpy(&ISA_Ctx.vendorName[8], &info[2], 4);
    ISA_DetectVendor();

    /* CPUID 1 */
    if (maxFn >= 1)
    {
        ISA_Cpuid(info, 1);

        FEATURE(3,  0, ISA_FEATURE_X86_FPU);
        FEATURE(3,  1, ISA_FEATURE_X86_VME);
        FEATURE(3,  2, ISA_FEATURE_X86_DE);
        FEATURE(3,  3, ISA_FEATURE_X86_PSE);
        FEATURE(3,  4, ISA_FEATURE_X86_TSC);
        FEATURE(3,  5, ISA_FEATURE_X86_MSR);
        FEATURE(3,  6, ISA_FEATURE_X86_PAE);
        FEATURE(3,  7, ISA_FEATURE_X86_MCE);
        FEATURE(3,  8, ISA_FEATURE_X86_CX8);
        FEATURE(3,  9, ISA_FEATURE_X86_APIC);
        FEATURE(3, 11, ISA_FEATURE_X86_SEP);
        FEATURE(3, 12, ISA_FEATURE_X86_MTRR);
        FEATURE(3, 13, ISA_FEATURE_X86_PGE);
        FEATURE(3, 14, ISA_FEATURE_X86_MCA);
        FEATURE(3, 15, ISA_FEATURE_X86_CMOV);
        FEATURE(3, 16, ISA_FEATURE_X86_PAT);
        FEATURE(3, 17, ISA_FEATURE_X86_PSE_36);
        FEATURE(3, 18, ISA_FEATURE_X86_PSN);
        FEATURE(3, 19, ISA_FEATURE_X86_CLFSH);
        FEATURE(3, 21, ISA_FEATURE_X86_DS);
        FEATURE(3, 22, ISA_FEATURE_X86_ACPI);
        FEATURE(3, 23, ISA_FEATURE_X86_MMX);
        FEATURE(3, 24, ISA_FEATURE_X86_FXSR);
        FEATURE(3, 25, ISA_FEATURE_X86_SSE);
        FEATURE(3, 26, ISA_FEATURE_X86_SSE2);
        FEATURE(3, 27, ISA_FEATURE_X86_SS);
        FEATURE(3, 28, ISA_FEATURE_X86_HTT);
        FEATURE(3, 29, ISA_FEATURE_X86_TM);
        FEATURE(3, 30, ISA_FEATURE_X86_IA64);
        FEATURE(3, 31, ISA_FEATURE_X86_PBE);

        FEATURE(2,  0, ISA_FEATURE_X86_SSE3);
        FEATURE(2,  1, ISA_FEATURE_X86_PCLMULQDQ);
        FEATURE(2,  2, ISA_FEATURE_X86_DTES64);
        FEATURE(2,  3, ISA_FEATURE_X86_MONITOR);
        FEATURE(2,  4, ISA_FEATURE_X86_DS_CPL);
        FEATURE(2,  5, ISA_FEATURE_X86_VMX);
        FEATURE(2,  6, ISA_FEATURE_X86_SMX);
        FEATURE(2,  7, ISA_FEATURE_X86_EST);
        FEATURE(2,  8, ISA_FEATURE_X86_TM2);
        FEATURE(2,  9, ISA_FEATURE_X86_SSSE3);
        FEATURE(2, 10, ISA_FEATURE_X86_CNXT_ID);
        FEATURE(2, 11, ISA_FEATURE_X86_SDBG);
        FEATURE(2, 12, ISA_FEATURE_X86_FMA);
        FEATURE(2, 13, ISA_FEATURE_X86_CX16);
        FEATURE(2, 14, ISA_FEATURE_X86_XTPR);
        FEATURE(2, 15, ISA_FEATURE_X86_PDCM);
        FEATURE(2, 17, ISA_FEATURE_X86_PCID);
        FEATURE(2, 18, ISA_FEATURE_X86_DCA);
        FEATURE(2, 19, ISA_FEATURE_X86_SSE4_1);
        FEATURE(2, 20, ISA_FEATURE_X86_SSE4_2);
        FEATURE(2, 21, ISA_FEATURE_X86_X2APIC);
        FEATURE(2, 22, ISA_FEATURE_X86_MOVBE);
        FEATURE(2, 23, ISA_FEATURE_X86_POPCNT);
        FEATURE(2, 24, ISA_FEATURE_X86_TSC_DEADLINE);
        FEATURE(2, 25, ISA_FEATURE_X86_AES);
        FEATURE(2, 26, ISA_FEATURE_X86_XSAVE);
        FEATURE(2, 27, ISA_FEATURE_X86_OSXSAVE);
        FEATURE(2, 28, ISA_FEATURE_X86_AVX);
        FEATURE(2, 29, ISA_FEATURE_X86_F16C);
        FEATURE(2, 30, ISA_FEATURE_X86_RDRND);
        FEATURE(2, 31, ISA_FEATURE_X86_HYPERVISOR);
    }

    /* CPUID 7_0 */
    if (maxFn >= 7)
    {
        ISA_Cpuid2(info, 7, 0);
        if (info[1] & (1 <<  5)) ISA_SetFeature(ISA_FEATURE_X86_AVX2);
        if (info[1] & (1 <<  3)) ISA_SetFeature(ISA_FEATURE_X86_BMI1);
        if (info[1] & (1 <<  8)) ISA_SetFeature(ISA_FEATURE_X86_BMI2);
        if (info[1] & (1 << 19)) ISA_SetFeature(ISA_FEATURE_X86_ADX);
    }
}
