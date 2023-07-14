#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>

typedef struct{
	GtkWidget *view;
	GtkTextBuffer *buffer;
}Test;

static void
print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
  g_print (data);
  char *po = data;
  po = "bonjour\n";
  printf (po);
}

static void
callbackTest (GtkWidget *widget, GtkWidget *TextView2)
{
  gchar msg = gtk_text_view_get_buffer (TextView2);
  char messag = "samuel\n";
  //g_strcpy(messag, msg);
  printf (&messag);
  g_print (&msg);
  //g_free(msg);
  //free(messag);
  /*GtkWidget *view =data.view;
	GtkTextBuffer *buffer = data.buffer;
  gtk_text_view_set_buffer(view, buffer);
  gtk_entry_get_text*/
}

static void
activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *grid2;
  GtkWidget *button;
  GtkWidget *button2;
  GtkWidget *TextView;
  GtkTextBuffer *buffer;
  GtkWidget *entree;
  char salut;
  char *p = &salut;
  p = "salut";
  Test test1;
  
  entree = gtk_entry_new ();
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  grid = gtk_grid_new ();
  grid2 =gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (window), grid);  
  gtk_window_set_child (GTK_WINDOW (grid), grid2);
  gtk_window_set_title(GTK_WINDOW(window), "Decouverte de GTK");  

  TextView = gtk_text_view_new ();
  gtk_grid_attach (GTK_GRID (grid), TextView, 0, 1, 1, 1);

  buffer = gtk_text_view_get_buffer ( GTK_TEXT_VIEW (TextView));
  gtk_text_buffer_set_text (buffer, p, -1);

  test1.view = TextView;
  test1.buffer = buffer;

  GtkWidget *label = gtk_label_new ("salut");
  gtk_grid_attach (GTK_GRID(grid2), label, 0,0,1,1);
  gtk_widget_set_size_request (label, 720, 480);
  gtk_grid_attach (GTK_WINDOW (grid), entree, 0, 2, 1, 1);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), p);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);
  

  button2 = gtk_button_new_with_label ("Bonjour");
  g_signal_connect (button2, "clicked", G_CALLBACK (callbackTest), TextView);
  gtk_grid_attach (GTK_GRID (grid), button2, 1, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), grid2, 0, 0, 1, 1);

  gtk_window_present (GTK_WINDOW (window));

}


int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
