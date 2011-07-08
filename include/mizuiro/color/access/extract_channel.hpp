//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness,
	typename Enable = void
>
struct extract_channel;

}
}
}

#endif