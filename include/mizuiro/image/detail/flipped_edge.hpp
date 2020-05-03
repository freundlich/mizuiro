//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_FLIPPED_EDGE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_FLIPPED_EDGE_HPP_INCLUDED

#include <mizuiro/no_init.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
Dim
flipped_edge(
	Dim const &_view_dim
)
{
	Dim ret{
		mizuiro::no_init{}
	};

	for(
		typename Dim::size_type index = 0;
		index < Dim::static_size - 1;
		++index
	)
	{
		ret[index] = _view_dim[index];
	}

	ret.back() = 1;

	return ret;
}

}
}
}

#endif
