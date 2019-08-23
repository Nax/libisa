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

#include <stddef.h>
#include <libisa/libisa.h>

static int ISA_CheckFeatureHelper(ISA_Feature feature, const uint8_t* arr)
{
    if ((size_t)feature >= FEATURES_SIZE * 8)
        return 0;
    return !!(arr[feature / 8] & (1 << (feature % 8)));
}

static void ISA_SetFeatureHelper(ISA_Feature feature, uint8_t* arr)
{
    arr[feature / 8] |= (1 << (feature % 8));
}

ISA_API int ISA_CheckFeature(ISA_Feature feature)
{
    return ISA_CheckFeatureHelper(feature, ISA_Ctx.features);
}

ISA_API int ISA_CheckFeatureHw(ISA_Feature feature)
{
    return ISA_CheckFeatureHelper(feature, ISA_Ctx.featuresHw);
}

void ISA_SetFeature(ISA_Feature feature)
{
    ISA_SetFeatureHw(feature);
    ISA_SetFeatureSw(feature);
}

void ISA_SetFeatureSw(ISA_Feature feature)
{
    ISA_SetFeatureHelper(feature, ISA_Ctx.features);
}

void ISA_SetFeatureHw(ISA_Feature feature)
{
    ISA_SetFeatureHelper(feature, ISA_Ctx.featuresHw);
}
