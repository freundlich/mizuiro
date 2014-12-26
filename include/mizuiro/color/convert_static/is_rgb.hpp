//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_IS_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_IS_RGB_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/mpl/bool.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

template<
	typename Format
>
using is_rgb
=
mizuiro::mpl::bool_<
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::red
	>::value
	||
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::green
	>::value
	||
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::blue
	>::value
>;

}
}
}

#endif
