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

RootNode::RootNode(Gtk::Viewport* p_viewPort)
{
    this->m_child = EntryNode();
    this->m_parent = null;
    p_viewPort->set_child(this->m_child->m_entry);
}

RootNode::~RootNode()
{
    delete this->m_child;
}
