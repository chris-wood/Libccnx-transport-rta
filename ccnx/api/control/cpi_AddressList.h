/*
 * Copyright (c) 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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
 * @file cpi_AddressList.h
 * @brief A list of CPIAddress instances.
 *
 * An AddressList is a list of addresses.
 * It wraps a PARCLinkedList for type saftey with CPIAddress.
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */
#ifndef libccnx_cpi_AddressList_h
#define libccnx_cpi_AddressList_h

#include <ccnx/api/control/cpi_Address.h>

struct cpi_addresslist;
/**
 * @typedef CPIAddressList
 * @abstract A list of CPIAddress instance pointers.
 */
typedef struct cpi_addresslist CPIAddressList;

/**
 * Create an instance of {@link CPIAddressList}
 *
 * @return NULL An error occurred
 * @return non-NULL A pointer to a valid CPIAddressList instance.
 *
 * Example:
 * @code
 * {
 *     CPIAddressList *list = cpiAddressList_Create();
 *
 * }
 * @endcode
 *
 * @see cpiAddressList_Destroy
 */
CPIAddressList *cpiAddressList_Create(void);

/**
 * Dellocate and destroy a CPIAddressList instance.
 *
 * @param [in] addressListPtr A pointer to a pointer to a valid {@link CPIAddressList}.
 *
 *
 * Example:
 * @code
 * {
 *     CPIAddressList *list = cpiAddressList_Create(void);
 *     cpiAddressList_Destroy(&list);
 * }
 * @endcode
 *
 * @see cpiAddressList_Create
 */
void cpiAddressList_Destroy(CPIAddressList **addressListPtr);

/**
 * Appends the address, taking ownership of the memory
 *
 * @param list A pointer to a CPIAddressList.
 * @param address must be non-null
 * @return The input list
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CPIAddressList *cpiAddressList_Append(CPIAddressList *list, CPIAddress *address);

/**
 * Creates a reference counted copy
 *
 * @param list A pointer to a valid {@link CPIAddressList}.
 *
 * @return An allocated list, you must destroy it.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CPIAddressList *cpiAddressList_Copy(const CPIAddressList *list);

/**
 * Determine if two CPIAddressList instances are equal.
 *
 * Two CPIAddressList instances are equal if, and only if, they have the same length,
 * with the same elements in the same order.
 *
 *
 * The following equivalence relations on non-null `CPIAddressList` instances are maintained:
 *
 *  * It is reflexive: for any non-null reference value x, `CPIAddressList_Equals(x, x)`
 *      must return true.
 *
 *  * It is symmetric: for any non-null reference values x and y,
 *    `CPIAddressList_Equals(x, y)` must return true if and only if
 *        `cpiAddressList_Equals(y, x)` returns true.
 *
 *  * It is transitive: for any non-null reference values x, y, and z, if
 *        `cpiAddressList_Equals(x, y)` returns true and
 *        `cpiAddressList_Equals(y, z)` returns true,
 *        then  `cpiAddressList_Equals(x, z)` must return true.
 *
 *  * It is consistent: for any non-null reference values x and y, multiple
 *      invocations of `cpiAddressList_Equals(x, y)` consistently return true or
 *      consistently return false.
 *
 *  * For any non-null reference value x, `cpiAddressList_Equals(x, NULL)` must
 *      return false.
 *
 * @param a A pointer to a `CPIAddressList` instance.
 * @param b A pointer to a `CPIAddressList` instance.
 * @return true if the two `CPIAddressList` instances are equal.
 *
 * Example:
 * @code
 * {
 *    CPIAddressList *a = cpiAddressList_Create();
 *    CPIAddressList *b = cpiAddressList_Create();
 *
 *    if (cpiAddressList_Equals(a, b)) {
 *        // true
 *    } else {
 *        // false
 *    }
 * }
 * @endcode
 */
bool cpiAddressList_Equals(const CPIAddressList *a, const CPIAddressList *b);

/**
 * Get the number of items in the list
 *
 * @param list A pointer to a {@link CPIAddressList}.
 * @return The number of items in the list.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
size_t cpiAddressList_Length(const CPIAddressList *list);

/**
 * Returns a const reference to an item.
 * Use CPIAddress_Copy if needed.
 *
 * Do not free or modify the returned value.
 * Use CPIAddress_Copy if you   need a mutable instance.
 *
 * @param list A pointer to a CPIAddressList.
 * @param item A value less than the number of items in the given {@link CPIAddressList}.
 * @return Asserts if item off end of list.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
const CPIAddress *cpiAddressList_GetItem(const CPIAddressList *list, size_t item);

/**
 * Returns a JSON array of the addresses
 *
 *   { "ADDRS" : [ {addr0}, {addr1}, ..., {addrN} ] }
 *
 * @param list A pointer to a CPIAddressList.
 * @return A JSON object, even if array empty
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
PARCJSONArray *cpiAddressList_ToJson(const CPIAddressList *list);

/**
 * Creates an address list based on a JSON array
 *
 *   { "ADDRS" : [ {addr0}, {addr1}, ..., {addrN} ] }
 *
 * @param json A pointer to a valid PARCJSON instance.
 * @return An allocated address list.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CPIAddressList *cpiAddressList_CreateFromJson(PARCJSONArray *json);

/**
 * Get a nul-terminated, C-string representation of the given {@link CPIAddressList}.
 *
 * @param list A pointer to a valid {@link CPIAddressList} instance.
 *
 * @return An allocate string representation of the {@link CPIAddressList} that must be freed via `parcMemory_Deallocate()`.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
char *cpiAddressList_ToString(const CPIAddressList *list);
#endif // libccnx_cpi_AddressList_h
