/*
 * Copyright (c) 2007-2011 Markus van Dijk
 * All rights reserved.
 *
 * This file is part of the xprintf project.
 * The xprintf project is open source software and distributed
 * under the terms of the Simplified BSD License:
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *	*	Redistributions of source code must retain the above copyright notice,
 * 		this list of conditions and the following disclaimer.
 *	*	Redistributions in binary form must reproduce the above copyright notice,
 * 		this list of conditions and the following disclaimer in the documentation
 * 		and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "test-rig.h"

#include <stdio.h>
#include <stdlib.h>

static test_printf_fn test_xprintf;

static int test_xprintf(struct test_printf_info *tpi, const char *expected,
		int expectedLen, const char *format, va_list ap) {
	char *resultString;
	int resultLen = vasprintf(&resultString, format, ap);
	int result = compareResult(tpi, expected, expectedLen, format,
			resultString, resultLen);
	free(resultString);
	return result;
}

int main(void) {

#ifdef __GNUC__
	// printf("===== __GNUC__: %d.%d.%d\n", __GNUC__ + 0, __GNUC_MINOR__ + 0, __GNUC_PATCHLEVEL__ + 0);
	printf("===== gcc: %s\n", __VERSION__);
#else
#error "===== unknown compiler ====="
#endif

#ifdef __STDC__
	//  __STDC_VERSION__ is a (long int)
	printf("===== __STDC_VERSION__: %ld\n", __STDC_VERSION__);
#else /* __STDC__ */
#error "===== compiled as not ISO-C99 ====="
#endif /* __STDC__ */

	setTestingHost(1);
	DEFINE_test_printf_info("vasprintf(HOST)", test_xprintf);

	test_all_iso(tpi);

	return endAllTests(tpi) != 0; // return 1 in case of errors
}
