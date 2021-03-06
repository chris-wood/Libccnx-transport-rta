/*
 * Copyright (c) 2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Patent rights are not granted under this agreement. Patent rights are
 *       available under FRAND terms.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX or PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <config.h>
#include <stdio.h>
#include "config_TestingComponent.h"

#include <ccnx/transport/transport_rta/core/components.h>

CCNxStackConfig *
testingUpper_ProtocolStackConfig(CCNxStackConfig *stackConfig)
{
    PARCJSONValue *value = parcJSONValue_CreateFromNULL();
    CCNxStackConfig *result = ccnxStackConfig_Add(stackConfig, testingUpper_GetName(), value);
    parcJSONValue_Release(&value);

    return result;
}

CCNxStackConfig *
testingLower_ProtocolStackConfig(CCNxStackConfig *stackConfig)
{
    PARCJSONValue *value = parcJSONValue_CreateFromNULL();
    CCNxStackConfig *result = ccnxStackConfig_Add(stackConfig, testingLower_GetName(), value);
    parcJSONValue_Release(&value);

    return result;
}

CCNxConnectionConfig *
testingUpper_ConnectionConfig(CCNxConnectionConfig *connConfig)
{
    PARCJSONValue *value = parcJSONValue_CreateFromNULL();
    CCNxConnectionConfig *result = ccnxConnectionConfig_Add(connConfig, testingUpper_GetName(), value);
    parcJSONValue_Release(&value);

    return result;
}

CCNxConnectionConfig *
testingLower_ConnectionConfig(CCNxConnectionConfig *connConfig)
{
    PARCJSONValue *value = parcJSONValue_CreateFromNULL();
    CCNxConnectionConfig *result = ccnxConnectionConfig_Add(connConfig, testingLower_GetName(), value);
    parcJSONValue_Release(&value);

    return result;
}

const char *
testingUpper_GetName()
{
    return RtaComponentNames[TESTING_UPPER];
}

const char *
testingLower_GetName()
{
    return RtaComponentNames[TESTING_LOWER];
}
