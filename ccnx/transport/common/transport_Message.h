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
 * @file transport_Message.h
 * @brief <#Brief Description#>
 *
 * NOTE: TransportMessage is being phased out for the CCNxTlvDictionary
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */
#ifndef Libccnx_transport_Message_h
#define Libccnx_transport_Message_h

#include <ccnx/common/codec/ccnxCodec_NetworkBuffer.h>

#include <ccnx/common/internal/ccnx_TlvDictionary.h>

struct transport_message;
/**
 *
 * @see TransportMessage_CreateFromCcnxMessage
 * @see TransportMessage_CreateFromMessage
 */
typedef struct transport_message TransportMessage;

/**
 * Stores a reference to the given dictionary
 *
 * The caller is responsible for releasing 'dictionary' as the transport message stores its own reference.
 *
 * @param [in] dictionary A pointer to a valid `CCNxTlvDictionary`
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
TransportMessage *transportMessage_CreateFromDictionary(CCNxTlvDictionary *dictionary);

bool transportMessage_isValid(const TransportMessage *message);

#ifdef TransportLibrary_DISABLE_VALIDATION
#  define transportMessage_OptionalAssertValid(_instance_)
#else
#  define transportMessage_OptionalAssertValid(_instance_) transportMessage_AssertValid(_instance_)
#endif
/**
 * Assert that the given `TransportMessage` instance is valid.
 *
 * @param [in] message A pointer to a valid TransportMessage instance.
 *
 * Example:
 * @code
 * {
 *     TransportMessage *a = transportMessage_CreateFromDictionary(dictionary);
 *
 *     transportMessage_AssertValid(a);
 *
 *     printf("Instance is valid.\n");
 *
 *     transportMessage_Release(&b);
 * }
 * @endcode
 */
void transportMessage_AssertValid(const TransportMessage *message);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CCNxTlvDictionary *transportMessage_GetDictionary(TransportMessage *tm);

/**
 * Destroy the transport message and everything inside it
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
void transportMessage_Destroy(TransportMessage **tmPtr);

typedef void (TransportMessage_Free)(void **);

/**
 * <#One Line Description#>
 *
 * Add some stack payload to a transport message.
 * Will not be freed.
 * This is typically used to put a pointer to the RtaConnection in the message.
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
void transportMessage_SetInfo(TransportMessage *tm, void *info, TransportMessage_Free *freefunc);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
void *transportMessage_GetInfo(const TransportMessage *tm);

bool transportMessage_IsControl(const TransportMessage *tm);
bool transportMessage_IsInterest(const TransportMessage *tm);
bool transportMessage_IsContentObject(const TransportMessage *tm);

/**
 * If in DEBUG mode, returns how long the message has been in the system
 *
 * If not in DEBUG mode, will always be {.tv_sec = 0, .tv_usec = 0}.  The time is based
 * on gettimeofday().
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
struct timeval transportMessage_GetDelay(const TransportMessage *tm);
#endif // Libccnx_transport_Message_h
