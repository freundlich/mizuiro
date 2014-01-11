//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_NEEDS_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_NEEDS_STORE_HPP_INCLUDED

#include <mizuiro/color/types/needs_store.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/needs_store_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace needs_store_ns
{

template<
	typename ImageFormat
>
mizuiro::color::types::needs_store<
	typename
	ImageFormat::color_format
>
needs_store_adl(
	mizuiro::image::types::needs_store_ns::tag,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif