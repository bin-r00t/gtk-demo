#include <gtk/gtk.h>

#include "trivial-application.h"

struct _MyApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE(MyApp, example_app,  GTK_TYPE_APPLICATION);

static void
example_app_init (ExampleApp *app)
{
    
}