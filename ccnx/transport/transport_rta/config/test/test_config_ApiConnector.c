/*
 * Copyright (c) 2013-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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
/**
 * Rta component configuration class unit test
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */

// Include the file(s) containing the functions to be tested.
// This permits internal static functions to be visible to this Test Framework.
#include "../config_ApiConnector.c"
#include <parc/algol/parc_SafeMemory.h>
#include <LongBow/unit-test.h>

#include "testrig_RtaConfigCommon.c"

LONGBOW_TEST_RUNNER(config_ApiConnector)
{
    // The following Test Fixtures will run their corresponding Test Cases.
    // Test Fixtures are run in the order specified, but all tests should be idempotent.
    // Never rely on the execution order of tests or share state between them.
    LONGBOW_RUN_TEST_FIXTURE(Global);
    LONGBOW_RUN_TEST_FIXTURE(Local);
}

// The Test Runner calls this function once before any Test Fixtures are run.
LONGBOW_TEST_RUNNER_SETUP(config_ApiConnector)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

// The Test Runner calls this function once after all the Test Fixtures are run.
LONGBOW_TEST_RUNNER_TEARDOWN(config_ApiConnector)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE(Global)
{
    LONGBOW_RUN_TEST_CASE(Global, apiConnector_ConnectionConfig_JsonKey);
    LONGBOW_RUN_TEST_CASE(Global, apiConnector_ConnectionConfig_ReturnValue);
    LONGBOW_RUN_TEST_CASE(Global, apiConnector_GetName);
    LONGBOW_RUN_TEST_CASE(Global, apiConnector_ProtocolStackConfig_JsonKey);
    LONGBOW_RUN_TEST_CASE(Global, apiConnector_ProtocolStackConfig_ReturnValue);
}

LONGBOW_TEST_FIXTURE_SETUP(Global)
{    
    longBowTestCase_SetClipBoardData(testCase, testRtaConfiguration_CommonSetup());
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Global)
{
    testRtaConfiguration_CommonTeardown(longBowTestCase_GetClipBoardData(testCase));
    uint32_t outstandingAllocations = parcSafeMemory_ReportAllocation(STDERR_FILENO);
    if (outstandingAllocations != 0) {
        printf("%s leaks memory by %d allocations\n", longBowTestCase_GetName(testCase), outstandingAllocations);
        return LONGBOW_STATUS_MEMORYLEAK;
    }
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_CASE(Global, apiConnector_ConnectionConfig_ReturnValue)
{
    TestData *data = longBowTestCase_GetClipBoardData(testCase);
    CCNxConnectionConfig *test = apiConnector_ConnectionConfig(data->connConfig);

    assertTrue(test == data->connConfig,
               "Did not return pointer to argument for chaining, got %p expected %p",
               (void *) test, (void *) data->connConfig);
}

LONGBOW_TEST_CASE(Global, apiConnector_ConnectionConfig_JsonKey)
{
    TestData *data = longBowTestCase_GetClipBoardData(testCase);
    testRtaConfiguration_ConnectionJsonKey(apiConnector_ConnectionConfig(data->connConfig),
                                           apiConnector_GetName());
}

LONGBOW_TEST_CASE(Global, apiConnector_GetName)
{
    testRtaConfiguration_ComponentName(apiConnector_GetName, RtaComponentNames[API_CONNECTOR]);
}

LONGBOW_TEST_CASE(Global, apiConnector_ProtocolStackConfig_JsonKey)
{
    TestData *data = longBowTestCase_GetClipBoardData(testCase);
    testRtaConfiguration_ProtocolStackJsonKey(apiConnector_ProtocolStackConfig(data->stackConfig),
                                              apiConnector_GetName());
}

LONGBOW_TEST_CASE(Global, apiConnector_ProtocolStackConfig_ReturnValue)
{
    TestData *data = longBowTestCase_GetClipBoardData(testCase);
    CCNxStackConfig *test = apiConnector_ProtocolStackConfig(data->stackConfig);

    assertTrue(test == data->stackConfig,
               "Did not return pointer to argument for chaining, got %p expected %p",
               (void *) test, (void *) data->stackConfig);
}

LONGBOW_TEST_FIXTURE(Local)
{
}

LONGBOW_TEST_FIXTURE_SETUP(Local)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Local)
{
    uint32_t outstandingAllocations = parcSafeMemory_ReportAllocation(STDERR_FILENO);
    if (outstandingAllocations != 0) {
        printf("%s leaks memory by %d allocations\n", longBowTestCase_GetName(testCase), outstandingAllocations);
        return LONGBOW_STATUS_MEMORYLEAK;
    }
    return LONGBOW_STATUS_SUCCEEDED;
}

int
main(int argc, char *argv[])
{
    LongBowRunner *testRunner = LONGBOW_TEST_RUNNER_CREATE(config_ApiConnector);
    int exitStatus = longBowMain(argc, argv, testRunner, NULL);
    longBowTestRunner_Destroy(&testRunner);
    exit(exitStatus);
}
