/**
 * @file rootNode.cpp
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

#include <gtkmm.h>

#include "rootNode.hpp"
#include "entryNode.hpp"

RootNode::RootNode(Gtk::Viewport* p_viewPort)
{
    m_child = new EntryNode();
    m_parent = NULL;
    Gtk::Widget* childWidget = this->m_child->get_widget();
    p_viewPort->add(*childWidget);
}

RootNode::~RootNode()
{
    delete this->m_child;
}

double RootNode::evaluate()
{
    return 0;
}

void RootNode::delete_child(IEvaluable* p_child){}

void RootNode::change_child(IEvaluable* p_child, operation_t p_type){}

Gtk::Widget* RootNode::get_widget(){}
