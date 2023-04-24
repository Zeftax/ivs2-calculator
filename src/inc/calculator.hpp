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

#endif // !CALCULATOR_HPP
