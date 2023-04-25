/**
 * @file calculator.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Unknown
 * @copyright GNU GPLv3
 */


#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

//! Operations that can be represented by the calculator,
typedef enum
{
    ADD,
    SUTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    ROOT,
    FACTORIAL,
    LOG
} operation_t;

//! Add a new operation node to the curently selected position
/*!
 *  @remarks    Puts the widget to the currently selected node, then changes it
 *              to point at the left child of the new widget.
 *  @param p_operation Type of the operation, whose widget to add.
 */
void add_node(operation_t p_operation);

//! Moves the selected position one node to the right
void shift_right();

//! Moves the selected position one node to the left
void shift_left();



#endif // !CALCULATOR_HPP
