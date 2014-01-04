//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/channel_value_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename Format,
	typename Channel
>
using
channel_value
=
decltype(
	channel_value_adl(
		std::declval<
			mizuiro::color::types::channel_value_ns::tag
		>(),
		mizuiro::color::format::make_tag_of<
			Format
		>(),
		std::declval<
			Channel
		>()
	)
);

}
}
}

#endif
