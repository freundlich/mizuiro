//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//![includes_object]
#include <mizuiro/color/object.hpp>
//![includes_object]
//![includes_access]
#include <mizuiro/color/channel/red.hpp>
//![includes_access]
//![includes_format]
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
//![includes_format]
//![includes_init]
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
//![includes_init]
//![includes_layout]
#include <mizuiro/color/layout/rgb.hpp>
//![includes_layout]
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
//![format_definition]
	using
	channel
	=
	std::uint8_t;

	using
	r8g8b8
	=
	mizuiro::color::format::homogenous_static<
		channel,
		mizuiro::color::layout::rgb
	>;
//![format_definition]

//![object_definition]
	using
	r8g8b8_color
	=
	mizuiro::color::object<
		r8g8b8
	>;
//![object_definition]

//![object_init]
	r8g8b8_color color(
		(mizuiro::color::init::red() = channel{42}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::green() %= 0.5) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::blue() = channel{100}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
//![object_init]

//![object_access]
	color.set(
		mizuiro::color::channel::red(),
		channel{10} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	std::cout
		<< color.get(
			mizuiro::color::channel::red()
		)
		<< '\n';
//![object_access]
}
