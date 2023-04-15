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
#include <gtkmm.h>

#include "ivs-math.hpp"
#include "calculatorWindow.hpp"

using namespace std;


int main(int argc, char **argv)
{
	Glib::RefPtr<Gtk::Application> app =
		Gtk::Application::create("org.gtkmm.examples.base");

	return app->make_window_and_run<CalculatorWindow>(argc, argv);
}
