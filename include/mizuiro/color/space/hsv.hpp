//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue_fwd.hpp>
#include <mizuiro/color/channel/saturation_fwd.hpp>
#include <mizuiro/color/channel/value_fwd.hpp>
#include <mizuiro/color/space/hsv_fwd.hpp>
#include <fcppt/metal/set/make.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct hsv
{
	using
	required_channels
	=
	fcppt::metal::set::make<
		mizuiro::color::channel::hue,
		mizuiro::color::channel::saturation,
		mizuiro::color::channel::value
	>;
};

}
}
}

#endif
