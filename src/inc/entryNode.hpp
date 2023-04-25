/**
 * @file entryNode.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Leaf node of the operational tree. You can enter numbers here.
 * @copyright GNU GPLv3
 */

#pragma once

#include <gtkmm.h>

//!	Leaf node of the operational tree.
/*!
 *	You can enter numbers here.
 */
class EntryNode : public IEvaluable
{
public:
	//! Constructor.
	EntryNode();

    //! Destructor.
	virtual ~EntryNode();

protected:
}
