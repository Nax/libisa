#include <string.h>
#include <libisa/libisa.h>

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
        if (info[3] & (1 <<  0)) ISA_SetFeature(ISA_FEATURE_X86_FPU);
        if (info[3] & (1 << 23)) ISA_SetFeature(ISA_FEATURE_X86_MMX);
        if (info[3] & (1 << 25)) ISA_SetFeature(ISA_FEATURE_X86_SSE);
        if (info[3] & (1 << 26)) ISA_SetFeature(ISA_FEATURE_X86_SSE2);
        if (info[2] & (1 <<  0)) ISA_SetFeature(ISA_FEATURE_X86_SSE3);
        if (info[2] & (1 <<  9)) ISA_SetFeature(ISA_FEATURE_X86_SSSE3);
        if (info[2] & (1 << 19)) ISA_SetFeature(ISA_FEATURE_X86_SSE4_1);
        if (info[2] & (1 << 20)) ISA_SetFeature(ISA_FEATURE_X86_SSE4_2);
        if (info[2] & (1 << 12)) ISA_SetFeature(ISA_FEATURE_X86_FMA);
        if (info[2] & (1 << 29)) ISA_SetFeature(ISA_FEATURE_X86_F16C);
        if (info[2] & (1 << 28)) ISA_SetFeature(ISA_FEATURE_X86_AVX);
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
