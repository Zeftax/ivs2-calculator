/*!
	\file iEvaluable.hpp
	\author Zdenek Borovec
	\author Tomas Krejci
	\author Jan Lozrt
	\author Jakub Mitrenga
	\copyright GNU GPLv3
*/


#pragma once

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
	//! Evaluate my numerical value
	/*!
	 *	Either return my value if I hold a number, or evaluete the expression
	 *	I am representing if I am an expression container.
	 *
	 *	\returns Numerical value of my insides.
	 */
	virtual double Evaluate() = 0;

	//! A destructor
	virtual inline ~IEvaluable() = 0;
}
IEvaluable::~IEvaluable(){}
