/* 
 *        Project:	birdy
 *       Filename:	main.c
 *    Description:	a twitter client
 *
 * 		  Version:	1.0
 * 		  Created:	2011-08-21
 * 		 Compiler:	gcc
 *
 * 		   Author:	Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "config.h"
#include "options.h"
#include "twitter.h"
#include "types.h"
#include "window.h"


int
main (int argc, char *argv[])
{
	size_t tweet_len, n;

	mode = MODE_GUI;

	if (argc > 1)
		parse_options (argc, argv);

	rcinit ();
	int rc = read_config ();

	/* create GUI */
	if (mode == MODE_GUI) {
		draw_main_window ();
	}
	else
		printf ("mode != gui\n");
	if (options->from_stdin == 1) {
		tweet_len = getline (&options->tweet_text, &n, stdin);
		printf ("You tweeted: \"%s\" (%d)\n", options->tweet_text, tweet_len);
	}

	return EXIT_SUCCESS;
}                                               /* end of main */
