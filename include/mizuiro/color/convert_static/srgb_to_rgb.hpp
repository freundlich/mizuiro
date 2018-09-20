//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_SRGB_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_SRGB_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/srgb_to_rgb.hpp>
#include <mizuiro/color/space/rgb_fwd.hpp>
#include <mizuiro/color/space/srgb_fwd.hpp>
#include <mizuiro/color/types/space.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

template<
	typename Dest,
	typename Src
>
inline
typename
std::enable_if<
	std::is_same<
		mizuiro::color::types::space<
			Dest
		>,
		mizuiro::color::space::rgb
	>::value
	&&
	std::is_same<
		mizuiro::color::types::space<
			typename
			Src::format
		>,
		mizuiro::color::space::srgb
	>::value
	,
	mizuiro::color::object<
		Dest
	>
>::type
convert(
	Src const &_src
)
{
	return
		mizuiro::color::conversion::srgb_to_rgb<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
