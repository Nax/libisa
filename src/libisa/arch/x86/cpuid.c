#include <isa/isa.h>

ISA_API void ISA_Cpuid(uint32_t* ret, uint32_t fn)
{
    ISA_Cpuid2(ret, fn, 0);
}
