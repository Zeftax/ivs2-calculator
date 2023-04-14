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

static void activate(GtkApplication *app, gpointer user_data)
{
	auto builder = Gtk::Builder::create_from_file("res/layout.glade");

	Gtk::Window* calcWindow = (Gtk::Window*) malloc(sizeof(Gtk::Window*));

	builder->get_widget("aboutWindow", calcWindow);

	app->add_window(*calcWindow);
	calcWindow->set_visible(true);
}

int main(int argc, char **argv)
{
	app = Gtk::Application::create("org.gtkmm.ratulator");

	app->signal_activate().connect([] () { on_app_activate(); });

	//Shows the window and returns when it is closed.
	return app->run(argc, argv);
}
