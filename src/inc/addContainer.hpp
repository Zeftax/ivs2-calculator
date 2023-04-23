/*!
	\file addContainer.hpp
	\author Zdenek Borovec
	\author Tomas Krejci
	\author Jan Lozrt
	\author Jakub Mitrenga
	\copyright GNU GPLv3
*/

#pragma once

#include <gtkmm.h>

//!	A container for the 'add' mathematical expression.
/*!
 *	Represents the binary addition (+) operation.
 */
class AddContainer : public Gtk::Widget, public IEvaluable
{
public:
	//! Constructor.
	AddContainer();
	virtual ~MyContainer();

	double Evaluate();

protected:
	//Overrides:
	Gtk::SizeRequestMode get_request_mode_vfunc() const override;
	void measure_vfunc(Gtk::Orientation orientation, int for_size, int& minimum, int& natural,
	int& minimum_baseline, int& natural_baseline) const override;
	void size_allocate_vfunc(int width, int height, int baseline) override;
#if 0
	void forall_vfunc(const ForeachSlot& slot) override;

	void on_add(Gtk::Widget* child) override;
	void on_remove(Gtk::Widget* child) override;
	GType child_type_vfunc() const override;
#endif
}
