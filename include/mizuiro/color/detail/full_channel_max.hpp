//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MAX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Type
>
typename
std::enable_if<
	std::is_integral<
		Type
	>::value,
	Type
>::type
full_channel_max()
{
	return
		std::numeric_limits<
			Type
		>::max();
}

template<
	typename Type
>
typename
std::enable_if<
	std::is_floating_point<
		Type
	>::value,
	Type
>::type
full_channel_max()
{
	return
		static_cast<
			Type
		>(
			1.0
		);
}

}
}
}

#endif
