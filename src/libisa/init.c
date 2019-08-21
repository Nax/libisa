#include <libisa/libisa.h>

ISA_Context ISA_Ctx;

ISA_API void ISA_Init(void)
{
    if (ISA_Ctx.initialized)
        return;

    ISA_Detect();

    ISA_Ctx.initialized = 1;
}
