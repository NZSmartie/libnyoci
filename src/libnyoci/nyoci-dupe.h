/*!	@file nyoci-dupe.h
**	@author Robert Quattlebaum <darco@deepdarc.com>
**	@brief Duplicate packet detection
**
**	Copyright (C) 2017 Robert Quattlebaum
**
**	Permission is hereby granted, free of charge, to any person
**	obtaining a copy of this software and associated
**	documentation files (the "Software"), to deal in the
**	Software without restriction, including without limitation
**	the rights to use, copy, modify, merge, publish, distribute,
**	sublicense, and/or sell copies of the Software, and to
**	permit persons to whom the Software is furnished to do so,
**	subject to the following conditions:
**
**	The above copyright notice and this permission notice shall
**	be included in all copies or substantial portions of the
**	Software.
**
**	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
**	KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
**	WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
**	PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
**	OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
**	OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
**	OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
**	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef NYOCI_nyoci_dupe_h
#define NYOCI_nyoci_dupe_h

#include "libnyoci.h"

struct nyoci_dupe_info_s {
	struct {
		uint32_t hash;
		nyoci_sockaddr_t from;
		coap_msg_id_t msg_id;
		coap_code_t code;
	} dupe[NYOCI_CONF_DUPE_BUFFER_SIZE];

#if NYOCI_CONF_DUPE_BUFFER_SIZE<=256
	uint8_t dupe_index;
#else
	uint16_t dupe_index;
#endif
};

bool nyoci_inbound_dupe_check(void);

#endif
