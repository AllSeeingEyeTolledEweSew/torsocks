/*
 * Copyright (C) 2013 - David Goulet <dgoulet@ev0ke.net>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 2 only, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef TORSOCKS_CONNECTION_H
#define TORSOCKS_CONNECTION_H

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "defaults.h"

enum connection_domain {
	CONNECTION_DOMAIN_INET	= 1,
	CONNECTION_DOMAIN_INET6	= 2,
};

struct connection_addr {
	enum connection_domain domain;
	union {
		struct sockaddr_in sin;
		struct sockaddr_in6 sin6;
	} u;
};

struct connection {
	/* Socket fd and also unique ID. */
	int fd;

	/* Location of the SOCKS5 server. */
	struct connection_addr socks5_addr;

	/* Remote destination that passes through Tor. */
	struct connection_addr dest_addr;

	/* Next connection of the linked list. */
	struct connection *next, *prev;
};

#endif /* TORSOCKS_CONNECTION_H */