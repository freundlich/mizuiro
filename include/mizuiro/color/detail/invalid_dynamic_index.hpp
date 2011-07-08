//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_INVALID_DYNAMIC_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INVALID_DYNAMIC_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

inline
mizuiro::size_type
invalid_dynamic_index()
{
	return
		static_cast<
			mizuiro::size_type
		>(
			-1
		);
}

}
}
}

#endif