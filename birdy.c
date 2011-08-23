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
#include "window.h"

int
main (int argc, char *argv[])
{
	rcinit ();
	parse_options (argc, argv);

	return EXIT_SUCCESS;
}                                               /* end of main */
