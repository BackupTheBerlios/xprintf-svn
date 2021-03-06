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

#include "test-runner.h"
#include "test-rig.h"

static int za = 10;
static int *zap = &za;

void test_pointers(struct test_printf_info *tpi) {
	startTests(tpi, __func__);

	zap++; // prevent variable zap to be optimized away

	TEST("0", "%p", 0); // MacOS: "0x0" [3]
	TEST("0", "%#p", 0); // MacOS: "0x0" [3]
	TEST("00000000", "%08p", 0); // MacOS: "0x000000" [8]
	TEST("00000000", "%#08p", 0); // MacOS: "0x000000" [8]
	TEST("00000000", "%08.8p", 0); // MacOS: "0x00000000" [10]
	TEST("00000000", "%#08.8p", 0); // MacOS: "0x00000000" [10]

	TESTHOST("%p", (void*) zap);
	TESTHOST("%#p", (void*) zap);
	TESTHOST("%8p", (void*) zap);
	TESTHOST("%#8p", (void*) zap);
	TESTHOST("%08p", (void*) zap);
	TESTHOST("%#08p", (void*) zap);
	TESTHOST("%.8p", (void*) zap);
	TESTHOST("%#.8p", (void*) zap);
	TESTHOST("%0.8p", (void*) zap);
	TESTHOST("%#0.8p", (void*) zap);
	TESTHOST("%08.8p", (void*) zap);
	TESTHOST("%#08.8p", (void*) zap);

	endTests(tpi);
}
