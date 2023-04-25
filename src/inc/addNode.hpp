/**
 * @file addNode.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief A container for the 'add' mathematical expression
 * @copyright GNU GPLv3
 */

#pragma once

#include <gtkmm.h>

//!	A container for the 'add' mathematical expression.
/*!
 *	Represents the binary addition (+) operation.
 */
class AddNode : public IEvaluable
{
public:
	//! Constructor.
	AddNode(IEvaluable* parent);

    //! Destructor.
	virtual ~AddContainer();

protected:
}
