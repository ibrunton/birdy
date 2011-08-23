/*
 *       Filename:  config.h
 *
 *    Description:  for reading config file
 *
 *        Version:  1.0
 *        Created:  2011-08-22 18:51
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
	char *username;
	char *password;

	int saveLogin;
	int autoLogin;

	int windowHeight;
	int windowWidth;
	int windowXpos;
	int windowYpos;
	int saveGeometry;

	int showClients;
	int showUserPics;
} config_t;

extern const config_t *config;

void _rcinit ();
int read_config ();
int write_config ();

#endif /* CONFIG_H */
