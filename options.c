/*
 *       Filename:  options.c
 *
 *    Description:  for parsing command-line options
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
#include <errno.h>

#include "config.h"

void print_usage ()
{
	printf ("usage: birdy [-t] [-g GEOMETRY] [TEXT]\n");
}

void print_version ()
{
	printf ("birdy %s - a GUI/CLI Twitter client in C and GTK\n", VERSION);
}

void parse_options (int argc, char **argv)
{

}
