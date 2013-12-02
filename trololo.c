/* trololo
 * Copyright © 2013 Przemysław Sitek <przemyslaw.sitek@gmail.com>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define VERSION "1.0"

/* Print helpful help message */
static void
print_help (const char *program_name)
{
	printf("%s: I CAN HAS POWER?\n", program_name);
}

/* Print version information */
static void
print_version (const char *program_name)
{
	printf("%s %s\n", program_name, VERSION);
}


int
main (int argc, char *argv[])
{
	/* Parse command line options */
	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			print_help(argv[0]);
			return 0;
		}

		if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
			print_version(argv[0]);
			return 0;
		}
	}

	/* Switch to superuser */
	if (setuid(0) != 0) {
		perror("bork, cannot switch user");
		return 1;
	}

	/* Execute shell */
	if (execl("/bin/bash", NULL, NULL) == -1) {
		perror("bork, cannot execute shell");
		return 2;
	}

	/* Not reachable */
	return 0;
}
