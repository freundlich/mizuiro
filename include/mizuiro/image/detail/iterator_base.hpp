#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator,
	typename Format,
	typename Constness
>
struct iterator_base {
	typedef boost::iterator_facade<
		Iterator,
		typename Format::channel_type,
		boost::random_access_traversal_tag,
		typename Format::color_format:: template reference<
			Constness
		>::type,
		difference_type
	> type;
};

}
}
}

#endif
