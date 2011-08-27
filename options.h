/*
 *       Filename:  options.h
 *
 *    Description:  for parsing command-line options
 *
 *        Version:  1.0
 *        Created:  2011-08-22 18:51
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */
#ifndef OPTIONS_H
#define OPTIONS_H

typedef struct {
	int tweet_textcnt;
	char **tweet_text;
	char *filename;
	char *geometry;
	unsigned char from_stdin;
} options_t;

extern const options_t *options;

void print_usage ();
void print_version ();
void parse_options (int, char**);

#endif /* OPTIONS_H */
