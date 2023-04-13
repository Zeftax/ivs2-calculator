/*************************************************
 * Application name: ratulator
 * Project: ivs2-calculator
 *
 * Date:         2023-04-10
 *************************************************/
/**
 * @file calculator.cpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Simple calculator app
 */

#include <iostream>
#include <gtk/gtk.h>
#include "ivs-math.hpp"

using namespace std;

static void demo(GtkWidget *widget, gpointer data)
{
    g_print("4 + 5 = %lf\n", ivsm::add(4, 5));
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Ratulator");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    button = gtk_button_new_with_label("4 + 5");

    g_signal_connect(button, "clicked", G_CALLBACK(demo), NULL);
    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    // IMPORTANT: first arg is window class!
    //                          ↓
    app = gtk_application_new("org.ratulator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return 0;
}
