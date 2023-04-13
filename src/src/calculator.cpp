/*************************************************
 * Application name: ratulator
 * Project: ivs2-calculator
 *
 * Date:         2023-04-10
 *************************************************/
/**
 * @file calculator.cpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief Simple calculator app
 */

#include <iostream>
#include "ivs-math.hpp"

using namespace std;

int main ()
{
    double res = ivsm::add(4, 5);
    cout << "4 + 5 = " << res << endl;
    return 0;
}
