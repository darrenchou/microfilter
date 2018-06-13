/*****************************************************************************
 * mscadaserv.cpp
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
 * Norway House OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2016: http://www.osorno.ca/
 * 
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>   

#include "osaut.h"
#include "shamemchl.h"
#include "osornoconf.h"
#include "oscadaserv.h"

//!****************************************************************************
//! function parces income string for any type of ip-address: IPv4 or IPv6nd;
//! checks them for validate value and copies this value into output parameter.
//! input:  'str_in' - string, expected to have format 'ip-adress/port-num';
//! output: 'str_out'- expected to be pre-allocated char[n] array (n >= 48)
//!****************************************************************************
//! returns values: 0 - if valid ip-address was not found or 1 - if suceed.
//!****************************************************************************
