//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


namespace
{

typedef
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::l
	>
>
format_2d;

typedef
mizuiro::image::store<
	format_2d
>
store_2d;
}

TEST_CASE(
	"iterator position",
	"[mizuiro]"
)
{
	store_2d field{
		store_2d::dim{
			2u,
			2u
		},
		mizuiro::no_init{}
	};

	store_2d::view_type const field_view{
		field.view()
	};

	store_2d::view_type::iterator it{
		field_view.begin()
	};

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			0u,
			0u
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			1u,
			0u
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			0u,
			1u
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			1u,
			1u
		)
	);
}
