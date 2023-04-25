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

//!	Parent node for all binary operations
class BinaryNode : public IEvaluable
{
public:
	//! Constructor.
	virtual BinaryNode(IEvaluable* parent) = 0;

    //! Destructor.
	~BinaryNode();

protected:
    //! The child on the left side of this operand.
    IEvaluable* m_lChild;

    //! The child on the right side of this operand.
    IEvaluable* m_pchild;
};
BinaryNode::~BinaryNode(){}
