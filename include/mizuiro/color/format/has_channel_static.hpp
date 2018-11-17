//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HAS_CHANNEL_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HAS_CHANNEL_STATIC_HPP_INCLUDED

#include <fcppt/brigand/found_t.hpp>
#include <mizuiro/color/types/static_channels.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename Format,
	typename Channel
>
using
has_channel_static
=
fcppt::brigand::found_t<
	mizuiro::color::types::static_channels<
		Format
	>,
	Channel
>;

}
}
}

#endif
