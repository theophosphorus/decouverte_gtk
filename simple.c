#include <gtk/gtk.h>

typedef struct{
	GtkWidget *view;
	GtkTextBuffer *buffer;
}Test;

static void
print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
  char *po = data;
  po = "bonjo";
}

static void
print_hello1 (GtkWidget *widget, gpointer data)
{
  g_print ("Allo le monde\n");
  /*GtkWidget *view =data.view;
	GtkTextBuffer *buffer = data.buffer;
  
  gtk_text_view_set_buffer(view, buffer);*/
}

static void
activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *button2;
  GtkWidget *TextView;
  GtkTextBuffer *buffer;
  char salut;
  char *p = &salut;
  p = "salut";
  Test test1;
  
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  grid = gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (window), grid);  
  gtk_window_set_title(GTK_WINDOW(window), "Decouverte de GTK");  

  TextView = gtk_text_view_new ();
  gtk_grid_attach (GTK_GRID (grid), TextView, 0, 2, 1, 1);

  buffer = gtk_text_view_get_buffer ( GTK_TEXT_VIEW (TextView));
  gtk_text_buffer_set_text (buffer, p, -1);

  test1.view = TextView;
  test1.buffer = buffer;

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), p);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);
  

  button2 = gtk_button_new_with_label ("Bonjour");
  g_signal_connect (button2, "clicked", G_CALLBACK (print_hello1), &test1);
  gtk_grid_attach (GTK_GRID (grid), button2, 1, 0, 1, 1);




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
