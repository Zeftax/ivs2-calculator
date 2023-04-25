/**
 * @file binaryNode.cpp
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
#include <stdexcept>

#include "binaryNode.hpp"

BinaryNode::delete_child(IEvaluable* p_child)
{
    // Zjistit jesi mazu leve nebo prave dite
    if(this->m_lChild == p_child)
    {
        // Smazu stare dite
        delete this->m_lChild;

        // Nahradim entry nodem
        this->m_lChild = EntryNode(this);
    }
    else if(this->m_rChild == p_child)
    {
        // Smazu stare dite
        delete this->m_rChild;

        // Nahradim entry nodem
        this->m_rChild = EntryNode(this);
    }
    else
    {
        throw std::invalid_argument( "Node is not a child of this node." );
    }
}

BinaryNode::change_child(IEvaluable* p_child, operation_t p_type)
{
    // Smazat stare dite
    // Zjistit jesi mazu leve nebo prave dite
    if(this->m_lChild == p_child)
    {
        // Smazu stare dite
        delete this->m_lChild;

        // Nahradim entry nodem
        this->m_lChild = EntryNode(this);
    }
    else if(this->m_rChild == p_child)
    {
        // Smazu stare dite
        delete this->m_rChild;

        // Nahradim entry nodem
        this->m_rChild = EntryNode(this);
    }
    else
    {
        throw std::invalid_argument( "Node is not a child of this node." );
    }
}
