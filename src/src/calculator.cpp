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
 * @brief Main for the calculator
 * @copyright GNU GPLv3
 */

#include <gtkmm/button.h>
#include <gtkmm/imagemenuitem.h>
#include <iostream>
#include <gtkmm.h>
#include <stdexcept>
#include <string>

#include "ivs-math.hpp"

namespace
{
enum Operator {
    NONE, PLUS, MINUS, MUL, DIV, EXP, ROOT, FAC, LOG
};

Gtk::Window* pDialog = nullptr;
Gtk::Window* pAbout = nullptr;
Glib::RefPtr<Gtk::Application> app;

Glib::RefPtr<Gtk::Label> labelPtr, resPtr, opPtr;

Operator prevOperator = NONE;

/**
 * @brief Moves value from result box to input box
 */
void ans()
{
    if (resPtr->get_text() != "-" && resPtr->get_text() != "ERROR")
    {
        labelPtr->set_text(resPtr->get_text());
        resPtr->set_text("-");
    }
}

/**
 * @brief Resets all values
 */
void clear()
{
    labelPtr->set_text("0");
    resPtr->set_text("-");
    opPtr->set_text("");
    prevOperator = NONE;
}

/**
 * @brief Deletes specified number of characters from input box from the back
 *
 * @param length Number of values to delete
 */
void del(int length)
{
    if (length <= 0)
        return;

    std::string curText = labelPtr->get_text();
    if (curText.size() <= length)
    {
        labelPtr->set_text("0");
        return;
    }

    curText.erase(curText.size() - length);

    labelPtr->set_text(curText);
}

/**
 * @brief Handles input of numbers
 *
 * @param val Value 0-9 as a string or "."
 */
void handle_input(std::string val)
{
    std::string curText = labelPtr->get_text();

    // no 0 at 1st position
    if (curText == "0" && val != ".")
    {
        labelPtr->set_text(val);
        return;
    }

    // allow only one .
    if (val == "." && curText.find(".") != std::string::npos) 
    {
        return;
    }

    labelPtr->set_text(curText + val);
}


/**
 * @brief Evaluates the result of specified operation
 */
void evaluate()
{
    double leftOp, rightOp, result;
    bool left = false;
    bool valid = true;
    
    if (((std::string) labelPtr->get_text()).back() == '.')
        del(1);

    std::string in = labelPtr->get_text();
    rightOp = std::stod(in);
    

    std::string res = resPtr->get_text();
    if (res != "-" && res != "ERROR")
    {
        leftOp = std::stod(res);
        left = true;
    }

    switch (prevOperator) {
        case PLUS:
            if (left)
                result = ivsm::add(leftOp, rightOp);
            else 
                result = rightOp;
            break;
        case MINUS:
            if (left)
                result = ivsm::subtract(leftOp, rightOp);
            else 
                result = rightOp;
            break;
        case MUL:
            if (left)
                result = ivsm::multiply(leftOp, rightOp);
            else 
                result = rightOp;
            break;
        case DIV:
            if (left)
                try {
                    result = ivsm::divide(leftOp, rightOp);
                } catch (std::invalid_argument) {
                    valid = false;
                }
            else 
                result = rightOp;
            break;
        case EXP:
            if (left)
                try {
                    result = ivsm::exponentiate(leftOp, rightOp);
                } catch (std::invalid_argument) {
                    valid = false;
                }
            else 
                result = rightOp;
            break;
        case ROOT:
            if (left)
                try {
                    result = ivsm::root(rightOp, leftOp);
                } catch (std::invalid_argument) {
                    valid = false;
                }
            else 
                result = rightOp;
            break;
        case LOG:
            if (left)
                try {
                    result = ivsm::log(rightOp, leftOp);
                } catch (std::invalid_argument) {
                    valid = false;
                }
            else 
                result = rightOp;
            break;
        case FAC:
            if (left)
                result = ivsm::factorial(leftOp);
            else 
                valid = false;
            break;
        case NONE:
        default:
            return;
    }

    if (!valid)
    {
        resPtr->set_text("ERROR");
    }
    else
        resPtr->set_text(std::to_string(result));

    prevOperator = NONE;
    opPtr->set_text("");

    del(in.size());
}

/**
 * @brief Chooses next action for evaluation
 *
 * @param op Operator
 */
void handle_operator(Operator op)
{
    resPtr->set_text(labelPtr->get_text());
    del(labelPtr->get_text().size());

    prevOperator = op;

    std::string lbl = "";
    switch (op) {
        case PLUS:
            lbl = "+";
            break;
        case MINUS:
            lbl = "-";
            break;
        case MUL:
            lbl = "*";
            break;
        case DIV:
            lbl = "/";
            break;
        case EXP:
            lbl = "exp:";
            break;
        case ROOT:
            lbl = "rad:";
            break;
        case LOG:
            lbl = "arg:";
            break;
        case FAC:
            evaluate();
            break;
        default:
            break;
    }

    opPtr->set_text(lbl);
}


/**
 * @brief Does nothing
 */
void aboutWindow(Glib::RefPtr<Gtk::Builder> refBuilder)
{
    
    refBuilder->get_widget("aboutWindow", pAbout);

    pAbout->show();
}


/**
 * @brief Maps GUI buttons to functions
 *
 * @param refBuilder Builder of window containing the buttons
 */
int connectButtons(Glib::RefPtr<Gtk::Builder> refBuilder)
{
    Glib::RefPtr<Gtk::Button> btnZero = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("zero"));
    if(!btnZero) return -1;
    btnZero->signal_clicked().connect([](){ handle_input("0"); });

    Glib::RefPtr<Gtk::Button> btnOne = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("one"));
    if(!btnOne) return -1;
    btnOne->signal_clicked().connect([](){ handle_input("1"); });

    Glib::RefPtr<Gtk::Button> btnTwo = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("two"));
    if(!btnTwo) return -1;
    btnTwo->signal_clicked().connect([](){ handle_input("2"); });

    Glib::RefPtr<Gtk::Button> btnThree = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("three"));
    if(!btnThree) return -1;
    btnThree->signal_clicked().connect([](){ handle_input("3"); });

    Glib::RefPtr<Gtk::Button> btnFour = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("four"));
    if(!btnFour) return -1;
    btnFour->signal_clicked().connect([](){ handle_input("4"); });

    Glib::RefPtr<Gtk::Button> btnFive = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("five"));
    if(!btnFive) return -1;
    btnFive->signal_clicked().connect([](){ handle_input("5"); });

    Glib::RefPtr<Gtk::Button> btnSix = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("six"));
    if(!btnSix) return -1;
    btnSix->signal_clicked().connect([](){ handle_input("6"); });

    Glib::RefPtr<Gtk::Button> btnSeven = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("seven"));
    if(!btnSeven) return -1;
    btnSeven->signal_clicked().connect([](){ handle_input("7"); });

    Glib::RefPtr<Gtk::Button> btnEight = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("eight"));
    if(!btnEight) return -1;
    btnEight->signal_clicked().connect([](){ handle_input("8"); });

    Glib::RefPtr<Gtk::Button> btnNine = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("nine"));
    if(!btnNine) return -1;
    btnNine->signal_clicked().connect([](){ handle_input("9"); });
    
    Glib::RefPtr<Gtk::Button> btnPoint = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("point"));
    if(!btnPoint) return -1;
    btnPoint->signal_clicked().connect([](){ handle_input("."); });

    Glib::RefPtr<Gtk::Button> btnEquals = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("equals"));
    if(!btnEquals) return -1;
    btnEquals->signal_clicked().connect([](){ evaluate(); });

    Glib::RefPtr<Gtk::Button> btnPlus = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("plus"));
    if(!btnPlus) return -1;
    btnPlus->signal_clicked().connect([](){ handle_operator(PLUS); });

    Glib::RefPtr<Gtk::Button> btnMinus = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("minus"));
    if(!btnMinus) return -1;
    btnMinus->signal_clicked().connect([](){ handle_operator(MINUS); });

    Glib::RefPtr<Gtk::Button> btnMul = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("mul"));
    if(!btnMul) return -1;
    btnMul->signal_clicked().connect([](){ handle_operator(MUL); });

    Glib::RefPtr<Gtk::Button> btnDiv = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("div"));
    if(!btnDiv) return -1;
    btnDiv->signal_clicked().connect([](){ handle_operator(DIV); });

    Glib::RefPtr<Gtk::Button> btnExp = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("exp"));
    if(!btnExp) return -1;
    btnExp->signal_clicked().connect([](){ handle_operator(EXP); });

    Glib::RefPtr<Gtk::Button> btnRoot = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("root"));
    if(!btnRoot) return -1;
    btnRoot->signal_clicked().connect([](){ handle_operator(ROOT); });

    Glib::RefPtr<Gtk::Button> btnFac = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("fac"));
    if(!btnFac) return -1;
    btnFac->signal_clicked().connect([](){ handle_operator(FAC); });

    Glib::RefPtr<Gtk::Button> btnLog = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("log"));
    if(!btnLog) return -1;
    btnLog->signal_clicked().connect([](){ handle_operator(LOG); });

    Glib::RefPtr<Gtk::Button> btnCE = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("clear"));
    if(!btnCE) return -1;
    btnCE->signal_clicked().connect([](){ clear(); });

    Glib::RefPtr<Gtk::Button> btnDel = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("del"));
    if(!btnDel) return -1;
    btnDel->signal_clicked().connect([](){ del(1); });

    Glib::RefPtr<Gtk::Button> btnAns = 
        Glib::RefPtr<Gtk::Button>::cast_dynamic(refBuilder->get_object("ans"));
    if(!btnAns) return -1;
    btnAns->signal_clicked().connect([](){ ans(); });

    return 0;
}

/**
 * @brief Maps keyboard keys to functions
 *
 * @param event Key press event
 */
bool on_key_press_or_release_event(GdkEventKey* event)
{
    if (event->type == GDK_KEY_PRESS)
    {
        switch (event->keyval) {
            case GDK_KEY_0:
                handle_input("0"); 
                return true;
            case GDK_KEY_1:
                handle_input("1"); 
                return true;
            case GDK_KEY_2:
                handle_input("2"); 
                return true;
            case GDK_KEY_3:
                handle_input("3"); 
                return true;
            case GDK_KEY_4:
                handle_input("4"); 
                return true;
            case GDK_KEY_5:
                handle_input("5"); 
                return true;
            case GDK_KEY_6:
                handle_input("6"); 
                return true;
            case GDK_KEY_7:
                handle_input("7"); 
                return true;
            case GDK_KEY_8:
                handle_input("8"); 
                return true;
            case GDK_KEY_9:
                handle_input("9"); 
                return true;
            case GDK_KEY_BackSpace:
                del(1); 
                return true;
            case GDK_KEY_Delete:
            case GDK_KEY_C:
            case GDK_KEY_c:
                clear(); 
                return true;
            case GDK_KEY_A:
            case GDK_KEY_a:
                ans(); 
                return true;
            case GDK_KEY_Return:
            case GDK_KEY_equal:
                evaluate(); 
                return true;
            case GDK_KEY_plus:
                handle_operator(PLUS);
                return true;
            case GDK_KEY_minus:
                handle_operator(MINUS);
                return true;
            case GDK_KEY_slash:
                handle_operator(DIV);
                return true;
            case GDK_KEY_asterisk:
                handle_operator(MUL);
                return true;
            case GDK_KEY_L:
            case GDK_KEY_l:
                handle_operator(LOG);
                return true;
            case GDK_KEY_R:
            case GDK_KEY_r:
                handle_operator(ROOT);
                return true;
            case GDK_KEY_E:
            case GDK_KEY_e:
                handle_operator(EXP);
                return true;
            case GDK_KEY_F:
            case GDK_KEY_f:
                handle_operator(FAC);
                return true;
        
            default:
                return false;
        }

    }
    return false;
}


void on_button_clicked()
{
  if (pDialog)
    pDialog->hide(); //hide() will cause Gtk::Application::run() to end.
}

/**
 * @brief Initialises the main window
 */
void on_app_activate()
{
    Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	try
	{
		refBuilder->add_from_resource("/org/ratulator/res/ratulator.glade");
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

	refBuilder->get_widget("calcWindow", pDialog);
	if (!pDialog)
	{
        std::cerr << "Could not get the dialog" << std::endl;
        return;
	}

	if (connectButtons(refBuilder) == -1)
	{
        std::cerr << "Failed to connect buttons" << std::endl;
        return;
	}

    auto inputLabel = 
        Glib::RefPtr<Gtk::Label>::cast_dynamic(refBuilder->get_object("inputLabel"));
    labelPtr = inputLabel;

    auto resLabel = 
        Glib::RefPtr<Gtk::Label>::cast_dynamic(refBuilder->get_object("resLabel"));
    resPtr = resLabel;

    auto opLabel = 
        Glib::RefPtr<Gtk::Label>::cast_dynamic(refBuilder->get_object("opLabel"));
    opPtr = opLabel;


	pDialog->signal_hide().connect([] () { delete pDialog; });


	app->add_window(*pDialog);
	pDialog->show();

    pDialog->signal_key_press_event().connect(sigc::ptr_fun(&on_key_press_or_release_event));
}
}

int main(int argc, char** argv)
{
	app = Gtk::Application::create("org.ratulator");

	app->signal_activate().connect([] () { on_app_activate(); });

	return app->run(argc, argv);
}
