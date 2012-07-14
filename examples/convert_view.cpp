//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/array.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/access/homogenous_raw.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_static.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_raw.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


namespace
{

template<
	typename Format
>
struct make_2d_format
{
	typedef mizuiro::image::interleaved<
		mizuiro::image::dimension<
			2
		>,
		Format
	> type;
};

}

int main()
{
	typedef boost::uint8_t base_type;

	typedef make_2d_format<
		mizuiro::color::homogenous_static<
			base_type,
			mizuiro::color::layout::rgba
		>
	>::type rgba_format;

	typedef make_2d_format<
		mizuiro::color::homogenous_static<
			base_type,
			mizuiro::color::layout::rgb
		>
	>::type rgb_format;

	typedef make_2d_format<
		mizuiro::color::homogenous_static<
			base_type,
			mizuiro::color::layout::rgba
		>
	>::type rgba_format;

	mizuiro::size_type const
		width(
			3
		),
		height(
			4
		);

	typedef mizuiro::array<
		unsigned char,
		width
		* height
		* sizeof(base_type)
		* rgb_format::color_format::element_count
	>::type raw_array;

	raw_array const data = {{
		152, 34, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		229, 59, 0,
		151, 228, 15,
		0, 39, 4
	}};

	typedef mizuiro::image::store<
		rgba_format,
		::mizuiro::access::raw
	> rgba_store;

	rgba_store::dim const dim(
		width,
		height
	);

	rgba_store store(
		dim
	);

	mizuiro::image::algorithm::copy_and_convert<
		mizuiro::color::convert_static::converter
	>(
		mizuiro::image::make_raw_view<
			rgb_format
		>(
			data.data(),
			dim,
			rgba_store::view_type::pitch_type::null()
		),
		store.view(),
		mizuiro::image::algorithm::may_overlap::no
	);

	mizuiro::image::algorithm::print(
		std::cout,
		store.view()
	);

	std::cout<< '\n';
}
