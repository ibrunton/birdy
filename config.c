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
#include "types.h"

config_t _config;
const config_t *config = (const config_t*) &config;

birdymode_t _mode;
const birdymode_t *mode = (const birdymode_t*) &mode;

geometry_t _geometry;
const geometry_t *geometry = (const geometry_t*) &geometry;

char *rcfile;

void rcinit ()
{
	/* set up config file path */
	char *xdgdir = getenv ("XDG_CONFIG_HOME");
	char *filebase = "/birdyrc";
	size_t len1 = strlen (xdgdir);
	size_t len2 = strlen (filebase);
	rcfile = malloc (len1 + len2 + 2);
	memcpy (rcfile, xdgdir, len1);
	memcpy (rcfile + len1, filebase, len2 + 1);
	
	/* set defaults */
	_mode = MODE_GUI;
	_config.saveLogin = 1;
	_config.autoLogin = 1;
	_config.defaultGUI = 1;
	_config.windowHeight = 640;
	_config.windowWidth = 480;
	_config.windowXpos = 0;
	_config.windowYpos = 0;
	_config.saveGeometry = 0;
	_config.showClients = 1;
	_config.showUserPics = 1;
	_config.displayPicsLocally = 0;

	_geometry.width = 640;
	_geometry.height=480;
	_geometry.x = 0;
	_geometry.y = 0;
}

int read_config ()
{
	int i, j;
	char line [80];
	char input_string [80];
	char field_name [80];
	char field_value [80];

	FILE *frc;
	if ((frc = fopen (rcfile, "r")) != NULL) {
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

			if (strcmp (field_name, "username\0") == 0) {
				_config.username = malloc (sizeof (field_value));
				strcpy (_config.username, field_value);
			}

			else if (strcmp (field_name, "password\0") == 0) {
				_config.password = malloc (sizeof (field_value));
				strcpy (_config.password, field_value);
			}

			else if (strcmp (field_name, "saveLogin\0") == 0)
				_config.saveLogin = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "autoLogin\0") == 0)
				_config.autoLogin = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "defaultGUI\0") == 0) {
				_config.defaultGUI = strtol (field_value, NULL, 10);
				if (_config.defaultGUI == 1)
					_mode = MODE_GUI;
				else
					_mode = MODE_CLI;
			}

			else if (strcmp (field_name, "windowHeight\0") == 0)
				_config.windowHeight = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "windowWidth\0") == 0)
				_config.windowWidth = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "windowXpos\0") == 0)
				_config.windowXpos = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "windowYpos\0") == 0)
				_config.windowYpos = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "saveGeometry\0") == 0)
				_config.saveGeometry = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "showUserPics\0") == 0)
				_config.showUserPics = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "showClients\0") == 0)
				_config.showClients = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "displayPicsLocally\0") == 0)
				_config.displayPicsLocally = strtol (field_value, NULL, 10);

			else if (strcmp (field_name, "bgColour1\0") == 0)
				strncpy (_config.bgColour1, field_value, 7); /* guaranteeds NULL-terminated */

			else if (strcmp (field_name, "bgColour2\0") == 0)
				strncpy (_config.bgColour2, field_value, 7);

			else if (strcmp (field_name, "fgColour1\0") == 0)
				strncpy (_config.fgColour1, field_value, 7);

			else if (strcmp (field_name, "fgColour2\0") == 0)
				strncpy (_config.fgColour2, field_value, 7);

		}
	} else {
		fprintf (stderr, "Cannot read config file: %s\n", strerror (errno));
		return -1;
	}

	fclose (frc);

	return 0;
}

int write_config ()
{
	return 0;
}
