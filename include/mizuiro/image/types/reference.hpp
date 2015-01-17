//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED

#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/types/reference_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Access,
	typename Format,
	typename Constness
>
using
reference
=
decltype(
	reference_adl(
		std::declval<
			mizuiro::image::types::reference_ns::tag
		>(),
		std::declval<
			Access
		>(),
		mizuiro::image::format::make_tag_of<
			Format
		>(),
		std::declval<
			Constness
		>()
	)
);

}
}
}

#endif
