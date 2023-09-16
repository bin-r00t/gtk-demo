#include <gtk/gtk.h>

/** btn 的 click 信号到达后的回调 */
static void
btn_click_handler(
    GtkWidget *widget,
    gpointer data)
{
    g_print("New Button Content\n");
}

int main(int argc, char **argv)
{

    GtkBuilder *builder;
    GObject *window; // 注意不再是 GtkWidget 了!...
    GObject *button; // 注意不再是 GtkWidget 了!...
    GError *error = NULL;

    gtk_init(&argc, &argv);

    /** load ui description file */
    builder = gtk_builder_new();
    if (gtk_builder_add_from_file(builder, "builder.ui", &error) == 0) {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return 1; // error happend!
    }
    
    window = gtk_builder_get_object(builder, "window");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    button = gtk_builder_get_object(builder, "button1");
    g_signal_connect(button, "clicked", G_CALLBACK(btn_click_handler), NULL);

    button = gtk_builder_get_object(builder, "button2");
    g_signal_connect(button, "clicked", G_CALLBACK(btn_click_handler), NULL);

    button = gtk_builder_get_object(builder, "quit");
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}