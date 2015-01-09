//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_AT_HPP_INCLUDED
#define MIZUIRO_MPL_AT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/detail/at.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	mizuiro::size_type Index
>
using
at
=
typename
mizuiro::mpl::detail::at<
	List,
	Index
>::type;

}
}

#endif
