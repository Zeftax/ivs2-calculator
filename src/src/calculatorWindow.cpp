#include <gtkmm.h>

#include "ivs-math.hpp"
#include "calculatorWindow.hpp"

CalculatorWindow::CalculatorWindow()
{
	set_title("Ratulator");
	set_default_size(200, 200);

	build_layout();
}

void CalculatorWindow::build_layout()
{
	auto builder = Gtk::Builder::create_from_file("res/ratulator.ui");
}
