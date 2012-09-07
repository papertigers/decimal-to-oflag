/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 *
 * Authors:
 *	Dave Eddy <dave@daveeddy.com>
 *	Mike Zeller <mike@mikezeller.net>
 *
 * 9/7/2012
 */


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	ALL_O_FLAGS	O_ACCMODE | O_NDELAY | O_NONBLOCK | O_APPEND | \
			O_SYNC | O_DSYNC | O_RSYNC | O_XATTR | \
			O_CREAT | O_TRUNC | O_EXCL | O_NOCTTY | O_LARGEFILE
/**
 * Taken from pfiles.c
 *
 * http://src.illumos.org/source/xref/illumos-gate/usr/src/cmd/ptools/pfiles/pfiles.c
 *
 * Copyright (c) 1994, 2010, Oracle and/or its affiliates. All rights reserved.
 */
static void
show_fileflags(int flags)
{
	char buffer[136];
	char *str = buffer;

	switch (flags & O_ACCMODE) {
	case O_RDONLY:
		(void) strcpy(str, "O_RDONLY");
		break;
	case O_WRONLY:
		(void) strcpy(str, "O_WRONLY");
		break;
	case O_RDWR:
		(void) strcpy(str, "O_RDWR");
		break;
	case O_SEARCH:
		(void) strcpy(str, "O_SEARCH");
		break;
	case O_EXEC:
		(void) strcpy(str, "O_EXEC");
		break;
	default:
		(void) sprintf(str, "0x%x", flags & O_ACCMODE);
		break;
	}

	if (flags & O_NDELAY)
		(void) strcat(str, "|O_NDELAY");
	if (flags & O_NONBLOCK)
		(void) strcat(str, "|O_NONBLOCK");
	if (flags & O_APPEND)
		(void) strcat(str, "|O_APPEND");
	if (flags & O_SYNC)
		(void) strcat(str, "|O_SYNC");
	if (flags & O_DSYNC)
		(void) strcat(str, "|O_DSYNC");
	if (flags & O_RSYNC)
		(void) strcat(str, "|O_RSYNC");
	if (flags & O_CREAT)
		(void) strcat(str, "|O_CREAT");
	if (flags & O_TRUNC)
		(void) strcat(str, "|O_TRUNC");
	if (flags & O_EXCL)
		(void) strcat(str, "|O_EXCL");
	if (flags & O_NOCTTY)
		(void) strcat(str, "|O_NOCTTY");
	if (flags & O_LARGEFILE)
		(void) strcat(str, "|O_LARGEFILE");
	if (flags & O_XATTR)
		(void) strcat(str, "|O_XATTR");
	if (flags & ~(ALL_O_FLAGS))
		(void) sprintf(str + strlen(str), "|0x%x",
		    flags & ~(ALL_O_FLAGS));

	(void) printf("%5d: %s\n", flags, str);
}

int main(int argc, char **argv) {
	int flags, i;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <flags int>\n", argv[0]);
		exit(1);
	}
	for (i = 1; i < argc; i++) {
		if ((flags = atoi(argv[i])) != 0)
			show_fileflags(flags);
		else
			fprintf(stderr, "%5d: error\n", flags);
	}
	exit(0);
}
