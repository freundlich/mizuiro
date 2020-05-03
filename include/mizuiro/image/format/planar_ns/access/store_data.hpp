//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_STORE_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_STORE_DATA_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/access/store_data_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
#include <mizuiro/image/format/planar_ns/types/store.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/store.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace store_data_ns
{

template<
	typename Access,
	typename Constness,
	typename ImageFormat
>
mizuiro::image::types::pointer<
	Access,
	ImageFormat,
	Constness
>
store_data_adl(
	mizuiro::image::access::store_data_ns::tag,
	mizuiro::image::format::planar_ns::tag<
		ImageFormat
	>,
	Access,
	Constness,
	mizuiro::image::format::store<
		ImageFormat
	> const &,
	mizuiro::apply_const<
		mizuiro::image::types::store<
			Access,
			ImageFormat
		> &,
		Constness
	> _store
)
{
	return
		fcppt::container::array::init<
			std::array<
				typename
				mizuiro::image::types::pointer<
					Access,
					ImageFormat,
					Constness
				>::value_type,
				ImageFormat::element_count
			>
		>(
			[
				&_store
			](
				mizuiro::size_type const _index
			)
			{
				return
					// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
					_store[
						_index
					].data();
			}
		);
}

}
}
}
}

#endif
