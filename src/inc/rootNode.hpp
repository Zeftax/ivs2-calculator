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

#include "iEvaluable.hpp"

//!	Node at the root of the operational tree.
/*!
 *  The calculator is initialized with this node.
 */
class RootNode : public IEvaluable
{
public:
	//! Constructor.
	RootNode(Gtk::Viewport* p_viewPort);

    //! Destructor.
	~RootNode();

	//! Evaluate my numerical value
	/*!
	 *	Either return my value if I hold a number, or evaluete the expression
	 *	I am representing if I am an expression container.
	 *
	 *	\returns Numerical value of my insides.
	 */
    double evaluate();

    //! Delete given child and replace it with an input node.
    /*!
     *  @remarks This function should be called by the child object
     *          on its parent.
     *  @param   p_child The child to be deleted.
     */
    void delete_child(IEvaluable* p_child);

    //! Change the childs type.
    /*!
     *  @remarks    This should be called by an entry node on its parent
     *              upon the change of the entry node to an operation node.
     *  @param  p_child The child to be replaced.
     *  @param  p_type  Type of the new child.
     */
    void change_child(IEvaluable* p_child, operation_t p_type);

protected:
    //! The child of the root node
    IEvaluable* m_child;
};
