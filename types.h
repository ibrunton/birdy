/*
 *       Filename:  types.h
 *
 *    Description:  data types
 *
 *        Version:  1.0
 *        Created:  <2011-08-26 Fri>
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#ifndef TYPES_H
#define TYPES_H

typedef enum {
	MODE_GUI,
	MODE_CLI
} birdymode_t;

extern const birdymode_t *mode;

typedef long long tweet_id;

typedef struct {
	char *user;
	char **text;
	tweet_id id;
	char *time;
} tweet_t;

typedef struct {
	int width;
	int height;
	int x;
	int y;
} geometry_t;

extern const geometry_t *geometry;

#endif /* TYPES_H */
