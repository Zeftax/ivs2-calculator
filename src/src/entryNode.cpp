/**
 * @file entryNode.cpp
 *
 * @author zdeněk borovec <xborov08@vutbr.cz>
 * @author tomáš krejčí <xkrejc84@vutbr.cz>
 * @author jan lozrt <xlozrt00@vutbr.cz>
 * @author jakub mitrenga <xmitre07@vutbr.cz>
 *
 * @brief leaf node of the operational tree. you can enter numbers here.
 * @copyright gnu gplv3
 */

#include <gtkmm.h>

#include "entryNode.hpp"

EntryNode::EntryNode()
{
    Gtk::Entry entry = Gtk::Entry();

    this->m_widget = &entry;
}

EntryNode::~EntryNode()
{

}

double EntryNode::evaluate()
{
    return 0;
}

void EntryNode::delete_child(IEvaluable* p_child){}

void EntryNode::change_child(IEvaluable* p_child, operation_t p_type){}
