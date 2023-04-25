/**
 * @file rootNode.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Node at the root of the operational tree.
 * @remarks The calculator is initialized with this node.
 * @copyright GNU GPLv3
 */

#pragma once

#include <gtkmm.h>

//!	Node at the root of the operational tree.
/*!
 *  The calculator is initialized with this node.
 */
class RootNode : public IEvaluable
{
public:
	//! Constructor.
	RootNode();

    //! Destructor.
	virtual ~RootNode();

protected:
}
