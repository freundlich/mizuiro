//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	convert_shuffle
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef boost::uint8_t channel_type;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::bgra
		>
	> bgra_color;

	rgba_color const rgba(
		(mizuiro::color::init::red() = static_cast<channel_type>(23))
		(mizuiro::color::init::blue() = static_cast<channel_type>(42))
		(mizuiro::color::init::green() = static_cast<channel_type>(100))
		(mizuiro::color::init::alpha() = static_cast<channel_type>(150))
	);

	bgra_color const bgra(
		mizuiro::color::convert<
			bgra_color::format
		>(
			rgba
		)
	);

	BOOST_CHECK(
		bgra.get(
			mizuiro::color::channel::red()
		)
		== static_cast<channel_type>(23)
	);

	BOOST_CHECK(
		bgra.get(
			mizuiro::color::channel::green()
		)
		== static_cast<channel_type>(100)
	);

	BOOST_CHECK(
		bgra.get(
			mizuiro::color::channel::blue()
		)
		== static_cast<channel_type>(42)
	);

	BOOST_CHECK(
		bgra.get(
			mizuiro::color::channel::alpha()
		)
		== static_cast<channel_type>(150)
	);
}
