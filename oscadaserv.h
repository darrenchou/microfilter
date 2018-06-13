/*****************************************************************************
 * oscadaserv.h
 *
 * begin   : Thu Oct 16 8:17:00 2016
 *
 * This file is part of OSAUT and OSORNOD projects. OSAUT is a free definition,
 * ehich may be used under the Creative Commons Share-alike license with the
 * additional condition of notifying the original author(s) of deviations and
 * expansion of the work.OSORNOD is intended to be released in the near future
 * as free software that you then can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, version 3. However,up to that point, OSORNOD software
 * and any or all of its components are proprietary and may not be modified or
 * distributed without express approval of Osorno Enterprises Inc.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * A copy of the GNU General Public License can be obtained from the Free 
 * Software Foundation, Inc., 51  Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA.
 *
 * Copyright Osorno Enterprises Inc., 2016
 *
 * OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2016: http://www.osorno.ca/
 * 
 ****************************************************************************/

#ifndef _OSCADASERV_H_
#define _OSCADASERV_H_

#define OSAUT_PORT_NUM  56678   // official registered with IANA OSAUT port number
//#define OSAUT_PORT_STR "6679"  // official registered with IANA OSAUT port number
#define OSAUT_PORT_STR "56678"  // official registered with IANA OSAUT port number
#define DEF_SCADA_PORT "36679" // default port number for External SCADA - unofficial

#define BACKLOG        5       // how many pending connections queue will hold

#define WAIT_TIME      30      // in seconds
#define TIME_OUT       8      // in seconds
#define MESSAGE_DELAY  3      // in seconds
#define NOT_AVAILABLE   "N/A"

extern void print_osaut_hex_and_bin(const char *data, int sizeofdata, int print_flag);
extern void copy_osaut_msg(char *copy_from, char *copy_to, int size);


//! print flags, - for using in print_osaut_hex_and_bin()
enum {
   PRINT_HEX = 1,
   PRINT_BIN = 2
};
extern void plc_server_new();

#endif