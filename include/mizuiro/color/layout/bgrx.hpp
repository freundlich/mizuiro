//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_BGRX_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_BGRX_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <mizuiro/color/layout/additive.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef layout::additive<
	boost::mpl::vector4<
		channel::blue,
		channel::green,
		channel::red,
		channel::undefined
	>
> bgrx;

}
}
}

#endif