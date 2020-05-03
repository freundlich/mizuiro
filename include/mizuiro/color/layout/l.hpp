//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_L_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_L_HPP_INCLUDED

#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/luminance.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

using
l
=
mizuiro::color::layout::make<
	mizuiro::color::space::luminance,
	metal::list<
		mizuiro::color::channel::luminance
	>
>;

}
}
}

#endif
