#include <gtk/gtk.h>

/** btn 的 click 信号到达后的回调 */
static void
btn_click_handler(
    GtkWidget *widget, 
    gpointer data) 
{
    g_print("Hello World\n");
}

static void
activate(
    GtkApplication *app, 
    gpointer user_data) 
{
    GtkWidget *window;
    // GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);

    // button = gtk_button_new_with_label("Click Me!");
    // g_signal_connect(button, "clicked", G_CALLBACK(btn_click_handler), NULL);
    // Tip: This api is for gtk4.0 only:
    // gtk_window_set_child(GTK_WINDOW(window), button);
    // Might need to use this subsitution:
    // gtk_container_add(GTK_WINDOW(window), button);

    // gtk_window_present(GTK_WINDOW(window));
    gtk_widget_show_all(window);
}


int 
main (int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}