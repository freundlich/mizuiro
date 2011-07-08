//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/conversion/same_to_same.hpp>
#include <mizuiro/color/layout/is_same.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{
namespace convert_static
{

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	layout::is_same<
		typename Dest::layout,
		typename Src::format::layout
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_src
)
{
	return
		conversion::same_to_same<
			Dest
		>(
			_src
		);
}

}
}
}

#endif