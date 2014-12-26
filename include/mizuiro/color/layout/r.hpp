//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_R_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_R_HPP_INCLUDED

#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/space/rgb.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef
mizuiro::color::space::rgb<
	mizuiro::mpl::list<
		mizuiro::color::channel::red
	>
>
r;

}
}
}

#endif
