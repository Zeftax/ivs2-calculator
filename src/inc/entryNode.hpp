/**
 * @file entrynode.hpp
 *
 * @author zdeněk borovec <xborov08@vutbr.cz>
 * @author tomáš krejčí <xkrejc84@vutbr.cz>
 * @author jan lozrt <xlozrt00@vutbr.cz>
 * @author jakub mitrenga <xmitre07@vutbr.cz>
 *
 * @brief leaf node of the operational tree. you can enter numbers here.
 * @copyright gnu gplv3
 */

#pragma once

#include <gtkmm.h>

#include "iEvaluable.hpp"

//!	leaf node of the operational tree.
/*!
 *	you can enter numbers here.
 */
class EntryNode : public IEvaluable
{
public:
	//! constructor.
	EntryNode();

    //! destructor.
	virtual ~EntryNode();

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
};
