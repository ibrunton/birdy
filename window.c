/*
 *       Filename:  window.c
 *
 *    Description:  for creating GUI
 *
 *        Version:  1.0
 *        Created:  <2011-08-26 Fri>
 *       Compiler:  gcc
 *
 *         Author:  Ian D Brunton (ib), iandbrunton@gmail.com
 *
 */

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include "config.h"
#include "options.h"
#include "types.h"
#include "window.h"

/* geometry_t _geometry; */
/* const geometry_t *geometry = (const geometry_t*) &geometry; */

void
draw_main_window ()
{
	GtkWidget *vbox;

	GtkWidget *menubar;
	GtkWidget *filemenu;
	GtkWidget *file;
	GtkWidget *new;
	GtkWidget *open;
	GtkWidget *quit;

	GtkWidget *viewmenu;
	GtkWidget *view;
	GtkWidget *tog_stat;

	GtkWidget *separator;

	GtkAccelGroup *accel_group = NULL;

	gint context_id;

	gtk_init (NULL, NULL);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (window), 480, 640); /* geometry->width, geometry->height); */
	gtk_window_set_title (GTK_WINDOW (window), "birdy");

	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);

	menubar = gtk_menu_bar_new ();
	filemenu = gtk_menu_new ();
	viewmenu = gtk_menu_new ();

	accel_group = gtk_accel_group_new ();
	gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);

	file = gtk_menu_item_new_with_mnemonic ("_File");
	quit = gtk_image_menu_item_new_from_stock (GTK_STOCK_QUIT, accel_group);

	view = gtk_menu_item_new_with_mnemonic ("_View");
	tog_stat = gtk_check_menu_item_new_with_label ("Show Statusbar");
	gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (tog_stat), TRUE);

	gtk_widget_add_accelerator (quit, "activate", accel_group,
								GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (file), filemenu);
	gtk_menu_shell_append (GTK_MENU_SHELL (filemenu), quit);
	gtk_menu_shell_append (GTK_MENU_SHELL (menubar), file);
	gtk_box_pack_start (GTK_BOX (vbox), menubar, FALSE, FALSE, 3);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (view), viewmenu);
	gtk_menu_shell_append (GTK_MENU_SHELL (viewmenu), tog_stat);
	gtk_menu_shell_append (GTK_MENU_SHELL (menubar), view);

	statusbar = gtk_statusbar_new ();
	gtk_box_pack_end (GTK_BOX (vbox), statusbar, FALSE, TRUE, 1);

	context_id = gtk_statusbar_get_context_id (GTK_STATUSBAR (statusbar), "birdy");

	g_signal_connect_swapped (G_OBJECT (window), "destroy",
							  G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect (G_OBJECT (quit), "activate",
					  G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect (G_OBJECT (tog_stat), "activate",
					  G_CALLBACK (toggle_statusbar), statusbar);

	gtk_widget_show_all (window);

	/* update_statusbar ("window is drawn"); */

	gtk_main ();

	return;
}

void
draw_settings_window ()
{
}

void
draw_tweet (tweet_t tweet)
{
}

void
toggle_statusbar (GtkWidget *widget, gpointer statusbar)
{
	if (gtk_check_menu_item_get_active (GTK_CHECK_MENU_ITEM (widget)) == 1)
		gtk_widget_show (statusbar);
	else
		gtk_widget_hide (statusbar);
}

void
update_statusbar (gchar *new_status)
{
	gtk_statusbar_pop (GTK_STATUSBAR (statusbar), 1);
	gtk_statusbar_push (GTK_STATUSBAR (statusbar), 1, new_status);

	gtk_main ();
}

void
statusbar_push (GtkWidget *widget, gpointer data, gchar *new_status)
{
	gtk_statusbar_push (GTK_STATUSBAR (statusbar), GPOINTER_TO_INT (data), new_status);
	return;
}

void
statusbar_pop (GtkWidget *widget, gpointer data)
{
	gtk_statusbar_pop (GTK_STATUSBAR (statusbar), GPOINTER_TO_INT (data));
	return;
}
