/**
 * @file iEvaluable.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Interface for evaluable elements
 * @copyright GNU GPLv3
 */

#pragma once

#include "calculator.hpp"

//! Interface for evaluable elements
/*!
 *	This interface is to be implemented by expression container widgets
 *	as well as the number widgets themselves.
 *	An element implementing this interface has to be able to evaluate its
 *	numerical value.
 */
class IEvaluable
{
public:
    //! A constructor
    virtual inline IEvaluable() = 0;

	//! A destructor
	virtual inline ~IEvaluable() = 0;

	//! Evaluate my numerical value
	/*!
	 *	Either return my value if I hold a number, or evaluete the expression
	 *	I am representing if I am an expression container.
	 *
	 *	\returns Numerical value of my insides.
	 */
	virtual double Evaluate() = 0;
    //! Delete given child and replace it with an input node.
    /*!
     *  @remarks This function should be called by the child object
     *          on its parent.
     *  @param   p_child The child to be deleted.
     */
    virtual void DeleteChild(IEvaluable* p_child) = 0;

    //! Change the childs type.
    /*!
     *  @remarks    This should be called by an entry node on its parent
     *              upon the change of the entry node to an operation node.
     *  @param  p_child The child to be replaced.
     *  @param  p_type  Type of the new child.
     */
    virtual void ChangeChild(IEvaluable* p_child, operation_t p_type) = 0;

protected:
    IEvaluable* m_parent;
}
IEvaluable::~IEvaluable(){}
