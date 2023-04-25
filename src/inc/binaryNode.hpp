/**
 * @file binaryNode.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief A mathematical operation node that has two operands (children);
 * @copyright GNU GPLv3
 */

#pragma once

#include <gtkmm.h>

//!	A container for the 'add' mathematical expression.
/*!
 *	Represents the binary addition (+) operation.
 */
class BinaryNode : public IEvaluable
{
public:
	//! Constructor.
	virtual BinaryNode(IEvaluable* parent) = 0;

    //! Destructor.
	virtual inline ~BinaryNode() = 0;

protected:
    //! The child on the left side of this operand.
    IEvaluable* m_lChild;

    //! The child on the right side of this operand.
    IEvaluable* m_pchild;
}
BinaryNode::~BinaryNode(){}
