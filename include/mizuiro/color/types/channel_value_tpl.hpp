//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_TPL_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_TPL_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>


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
struct channel_value_tpl
{
	typedef
	mizuiro::color::types::channel_value<
		Format,
		Channel
	>
	type;
};

}
}
}

#endif