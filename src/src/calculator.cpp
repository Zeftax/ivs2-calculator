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

namespace
{
Gtk::Window* pDialog = nullptr;
Glib::RefPtr<Gtk::Application> app;

void on_button_clicked()
{
  if (pDialog)
    pDialog->hide(); //hide() will cause Gtk::Application::run() to end.
}

void on_app_activate()
{
  // Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("res/ratulator.ui");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return;
  }

  // Get the GtkBuilder-instantiated dialog:
  pDialog = refBuilder->get_widget<Gtk::Window>("calcWindow");
  if (!pDialog)
  {
    std::cerr << "Could not get the dialog" << std::endl;
    return;
  }
/*
  // Get the GtkBuilder-instantiated button, and connect a signal handler:
  auto pButton = refBuilder->get_widget<Gtk::Button>("quit_button");
  if (pButton)
    pButton->signal_clicked().connect([] () { on_button_clicked(); });
*/
  // It's not possible to delete widgets after app->run() has returned.
  // Delete the dialog with its child widgets before app->run() returns.
  pDialog->signal_hide().connect([] () { delete pDialog; });

  app->add_window(*pDialog);
  pDialog->show();
}
} // anonymous namespace

int main(int argc, char** argv)
{
  app = Gtk::Application::create("org.gtkmm.example");

  // Instantiate a dialog when the application has been activated.
  // This can only be done after the application has been registered.
  // It's possible to call app->register_application() explicitly, but
  // usually it's easier to let app->run() do it for you.
  app->signal_activate().connect([] () { on_app_activate(); });

  return app->run(argc, argv);
}
