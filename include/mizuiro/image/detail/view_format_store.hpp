//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_VIEW_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_VIEW_FORMAT_STORE_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename FormatStore
>
struct view_format_store
{
	typedef FormatStore result_type;

	template<
		typename View
	>
	result_type const
	operator()(
		View const &_view
	) const
	{
		return
			_view.format_store();
	}
};

}
}
}

#endif