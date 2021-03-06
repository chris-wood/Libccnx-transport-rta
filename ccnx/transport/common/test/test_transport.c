/*
 * Copyright (c) 2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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

// Include the file(s) containing the functions to be tested.
// This permits internal static functions to be visible to this Test Runner.
#include "../transport.c"

#include <LongBow/unit-test.h>

#include <parc/algol/parc_SafeMemory.h>
#include <parc/testing/parc_TestingMemory.h>

LONGBOW_TEST_RUNNER(transport)
{
    // The following Test Fixtures will run their corresponding Test Cases.
    // Test Fixtures are run in the order specified here, but every test must be idempotent.
    // Never rely on the execution order of tests or share state between them.
    LONGBOW_RUN_TEST_FIXTURE(Global);
    LONGBOW_RUN_TEST_FIXTURE(Static);
}

// The Test Runner calls this function once before any Test Fixtures are run.
LONGBOW_TEST_RUNNER_SETUP(transport)
{
    parcMemory_SetInterface(&PARCSafeMemoryAsPARCMemory);
    return LONGBOW_STATUS_SUCCEEDED;
}

// The Test Runner calls this function once after all the Test Fixtures are run.
LONGBOW_TEST_RUNNER_TEARDOWN(transport)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE(Global)
{
    LONGBOW_RUN_TEST_CASE(Global, Transport_Create_RTA);
    LONGBOW_RUN_TEST_CASE(Global, Transport_Close);
    LONGBOW_RUN_TEST_CASE(Global, Transport_Destroy);
    LONGBOW_RUN_TEST_CASE(Global, Transport_Open);
    LONGBOW_RUN_TEST_CASE(Global, Transport_PassCommand);
    LONGBOW_RUN_TEST_CASE(Global, Transport_Recv);
    LONGBOW_RUN_TEST_CASE(Global, Transport_Send);
}

LONGBOW_TEST_FIXTURE_SETUP(Global)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Global)
{
    LongBowStatus result = LONGBOW_STATUS_SUCCEEDED;
    if (parcTestingMemory_ExpectedOutstanding(0, "%s", longBowTestCase_GetFullName(testCase)) == false) {
        result = LONGBOW_STATUS_MEMORYLEAK;
    }
    return result;
}

LONGBOW_TEST_CASE(Global, Transport_Close)
{
    testUnimplemented("");
}

LONGBOW_TEST_CASE(Global, Transport_Create_RTA)
{
    TransportContext *transport = Transport_Create(TRANSPORT_RTA);

    Transport_Destroy(&transport);
}

LONGBOW_TEST_CASE(Global, Transport_Destroy)
{
    TransportContext *transport = Transport_Create(TRANSPORT_RTA);

    Transport_Destroy(&transport);
}

LONGBOW_TEST_CASE(Global, Transport_Open)
{
    TransportContext *transport = Transport_Create(TRANSPORT_RTA);


    Transport_Destroy(&transport);
}

LONGBOW_TEST_CASE(Global, Transport_PassCommand)
{
    testUnimplemented("");
}

LONGBOW_TEST_CASE(Global, Transport_Recv)
{
    testUnimplemented("");
}

LONGBOW_TEST_CASE(Global, Transport_Send)
{
    testUnimplemented("");
}

LONGBOW_TEST_FIXTURE(Static)
{
}

LONGBOW_TEST_FIXTURE_SETUP(Static)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Static)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

int
main(int argc, char *argv[])
{
    LongBowRunner *testRunner = LONGBOW_TEST_RUNNER_CREATE(transport);
    int exitStatus = longBowMain(argc, argv, testRunner, NULL);
    longBowTestRunner_Destroy(&testRunner);
    exit(exitStatus);
}
