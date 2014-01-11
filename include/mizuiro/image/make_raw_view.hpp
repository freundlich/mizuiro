//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/is_raw_pointer.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/raw_view_from_pointer.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Pointer
>
typename
boost::enable_if<
	mizuiro::is_raw_pointer<
		Pointer
	>,
	mizuiro::image::detail::raw_view_from_pointer<
		Format,
		Pointer
	>
>::type const
make_raw_view(
	Pointer const _data,
	typename
	mizuiro::image::detail::raw_view_from_pointer<
		Format,
		Pointer
	>::dim const &_size,
	typename
	mizuiro::image::detail::raw_view_from_pointer<
		Format,
		Pointer
	>::pitch_type const &_pitch
)
{
	return
		mizuiro::image::detail::raw_view_from_pointer<
			Format,
			Pointer
		>(
			_size,
			_data,
			_pitch
		);
}

}
}

#endif
