//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_HPP_INCLUDED

#include <mizuiro/detail/copy_n.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iterator>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Dest
>
void
copy(
	Source const *const _begin,
	Source const *const _end,
	Dest *const _dest
)
{
	return
		mizuiro::detail::copy_n(
			_begin,
			std::distance(
				_begin,
				_end
			),
			_dest
		);
}

}
}

#endif
