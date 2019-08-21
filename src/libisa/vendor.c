#include <libisa/libisa.h>

ISA_API ISA_Vendor ISA_VendorID(void)
{
    return ISA_Ctx.vendorId;
}

ISA_API const char* ISA_VendorName(void)
{
    return ISA_Ctx.vendorName;
}
