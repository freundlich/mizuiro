//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal/list/at.hpp>
#include <metal/list/find.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace heterogenous
{

template<
	typename Format,
	typename Channel
>
using channel_bits
=
metal::at<
	typename
	Format::channel_bits,
	metal::find<
		typename Format::layout::channels,
		Channel
	>
>;

}
}
}
}

#endif
