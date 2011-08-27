/*
 *       Filename:  options.c
 *
 *    Description:  for parsing command-line options
 *					applicable to current instance only
 *
 *        Version:  1.0
 *        Created:  2011-08-22 21:04
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "options.h"
#include "types.h"

options_t _options;
const options_t *options = (const options_t*) &options;

void print_usage ()
{
	printf ("usage: birdy [-htv] [-f FILE] [-g GEOMETRY] [TEXT]\n");
}

void print_version ()
{
	printf ("birdy %s - a GUI/CLI Twitter client in C and GTK\n", VERSION);
}

void parse_options (int argc, char **argv)
{
	int opt;
	while ((opt = getopt (argc, argv, "f:g:htv")) != -1) {
		switch (opt) {
			case '?':
				print_usage ();
				exit (1);
				break;
			case 'f':
				_options.filename = optarg;
				break;
			case 'g':
				_options.geometry = optarg;
				/*...*/
				break;
			case 'h':
				print_usage ();
				exit (0);
				break;
			case 't':
				mode = MODE_CLI;
				break;
			case 'v':
				print_version ();
				exit (0);
				break;
		}
	}

	_options.tweet_text = argv + optind;
	_options.tweet_textcnt = argc - optind;
	_options.from_stdin = _options.tweet_textcnt == 1 &&
		strcmp (_options.tweet_text[0], "-") == 0;

	if (mode == MODE_GUI && _options.tweet_text <= argv)
		_options.from_stdin = 1;
}
