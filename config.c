/*
 *       Filename:  config.c
 *
 *    Description:  read and write configuration file
 *
 *        Version:  1.0
 *        Created:  2011-08-22 19:09
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "config.h"

config_t _config;
const config_t *config = (const config_t*) &config;

char *rcfile;

void _rcinit ()
{
	char *xdgdir = getenv ("XDG_CONFIG_HOME");
	char *filebase = "/birdyrc\0";
	size_t len1 = strlen (xdgdir);
	size_t len2 = strlen (filebase);
	rcfile = malloc (len1 + len2 + 2);
	memcpy (rcfile, xdgdir, len1);
	memcpy (rcfile + len1, filebase, len2 + 1);
}

int read_config ()
{
	int i, j;
	char line [80];
	char input_string [80];
	char field_name [80];
	char field_value [80];

	FILE *frc;
	if ((frc = fopen (rcfile, "r")) == 0) {
		while (fgets (line, 80, frc) != NULL) {
			sscanf (line, "%s", &input_string);
			if (input_string[0] == '#' || input_string[0] == '\n')
				continue;

			for (i = 0; input_string[i] != '='; i++) {
				field_name[i] = input_string[i];
			}
			field_name[i] = '\0';
			i++;

			for (j = 0; input_string[i] != '\0'; i++) {
				field_value[j] = input_string[i];
				++j;
			}
			field_value[j] = '\0';

			if (strcmp (field_name, "username\0") == 0)
				strcpy (_config.username, field_value);

			else if (strcmp (field_name, "password\0") == 0)
				strcpy (_config.password, field_value);

			else if (strcmp (field_name, "save_login\0") == 0)
				_config.saveLogin = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "auto_login\0") == 0)
				_config.autoLogin = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "window_height\0") == 0)
				_config.windowHeight = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "window_width\0") == 0)
				_config.windowWidth = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "window_x_pos\0") == 0)
				_config.windowXpos = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "window_y_pos\0") == 0)
				_config.windowYpos = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "save_geometry\0") == 0)
				_config.saveGeometry = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "show_user_pics\0") == 0)
				_config.showUserPics = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "show_clients\0") == 0)
				_config.showClients = strtol (field_value, NULL, 10);

		}
	} else {
		fprintf (stderr, "Cannot read config file: %s", strerror (errno));
		return -1;
	}

	fclose (frc);

	return 0;
}

int write_config ()
{
	return 0;
}
