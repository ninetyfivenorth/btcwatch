/*
	Copyright (C) 2013 Marco Scannadinari

	This file is part of btcwatch.

	btcwatch is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	btcwatch is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with btcwatch.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include "../include/cmdlineutils.h"
#include "../include/btcdbg.h"

noreturn void help(const char *const prog_name, const char *const optstring) {
	#if DEBUG
	btcdbg(__FILE__, __LINE__, "help()");
	#endif

	printf("Usage: %s -[%s]\n", prog_name, optstring);
	puts(
		"Get Bitcoin trade information\n"
		"\n"
		"Options:\n"
		"  -?, -h         --help                 print this help\n"
		"  -V             --version              print version number\n"
		"  -a             --all                  equivalent to -pbs\n"
		"  -b             --buy                  print buy price\n"
		"  -c CURRENCY    --currency=CURRENCY    set conversion currency\n"
		"  -p             --ping                 check for a successful JSON response\n"
		"  -s             --sell                 print sell price\n"
		"  -v             --verbose              increase verbosity\n"
		"\n"
		"Report bugs to <marco@scannadinari.co.uk>\n"
		"btcwatch home page: <https://github.com/marcoms/btcwatch/>"
	);

	exit(EXIT_SUCCESS);
}

void resetb(void) {
	freopen(NULL, "a", stdout);
	fwide(stdout, -1);
}

void resetw(void) {
	freopen(NULL, "a", stdout);
	fwide(stdout, 1);
}

noreturn void version(const char *const version) {
	#if DEBUG
	btcdbg(__FILE__, __LINE__, "version()");
	#endif

	printf("btcwatch %s\n", version);
	puts(
		"Copyright (C) 2007 Free Software Foundation, Inc.\n"
		"License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n"
		"This is free software: you are free to change and redistribute it.\n"
		"There is NO WARRANTY, to the extent permitted by law."
	);
	

	#if DEBUG
	btcdbg(__FILE__, __LINE__, "compiled with %s %s on %s %s", CC, CFLAGS, __TIME__, __DATE__);
	#endif

	exit(EXIT_SUCCESS);
}