/*
 *       Filename:  window.h
 *
 *    Description:  for constructing graphical interface
 *
 *        Version:  1.0
 *        Created:  2011-08-22 18:51
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *statusbar;

void draw_main_window ();
void draw_settings_window ();
void draw_tweet (tweet_t);
void toggle_statusbar (GtkWidget*, gpointer);
void update_statusbar (gchar*);
void statusbar_push (GtkWidget*, gpointer, gchar*);
void statusbar_pop (GtkWidget*, gpointer);

#endif /* WINDOW_H */
