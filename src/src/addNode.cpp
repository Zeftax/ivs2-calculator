
/**
 * @file addNode.cpp
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

#include "addNode.hpp"

AddNode::DeleteChild(IEvaluable* child)
{
    // Pridat entrynode jako nove dite namisto mazaneho ditete

    // Zjistit jesi mazu leve nebo prave dit
    if(this.m_lChild == child)
    {
        //smazat to dite
    }

    // pridat to entrynode
}
