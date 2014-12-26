//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ENUM_SIZE_HPP_INCLUDED
#define MIZUIRO_ENUM_SIZE_HPP_INCLUDED

#include <mizuiro/enum_size_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Enum
>
struct enum_size
:
mizuiro::mpl::integral_size<
	static_cast<
		mizuiro::size_type
	>(
		Enum::mizuiro_enum_maximum
	)
	+
	1u
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}

#endif
