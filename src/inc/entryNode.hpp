/**
 * @file entrynode.hpp
 *
 * @author zdeněk borovec <xborov08@vutbr.cz>
 * @author tomáš krejčí <xkrejc84@vutbr.cz>
 * @author jan lozrt <xlozrt00@vutbr.cz>
 * @author jakub mitrenga <xmitre07@vutbr.cz>
 *
 * @brief leaf node of the operational tree. you can enter numbers here.
 * @copyright gnu gplv3
 */

#pragma once

#include <gtkmm.h>

//!	leaf node of the operational tree.
/*!
 *	you can enter numbers here.
 */
class entrynode : public ievaluable
{
public:
	//! constructor.
	entrynode();

    //! destructor.
	virtual ~entrynode();

protected:
}
