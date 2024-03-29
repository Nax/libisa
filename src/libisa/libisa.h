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

#ifndef LIBISA_INCLUDED_H
#define LIBISA_INCLUDED_H 1

#include <isa/isa.h>

#if defined(ISA_ARCH_X86)
# define FEATURES_SIZE  16
#else
# define FEATURES_SIZE  1
#endif

typedef struct {
    int         initialized;
    ISA_Vendor  vendorId;
    char        vendorName[13];
    uint8_t     features[FEATURES_SIZE];
    uint8_t     featuresHw[FEATURES_SIZE];
} ISA_Context;

extern ISA_Context ISA_Ctx;

void ISA_Detect(void);
void ISA_SetFeature(ISA_Feature feature);
void ISA_SetFeatureSw(ISA_Feature feature);
void ISA_SetFeatureHw(ISA_Feature feature);

#endif
