//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_BOTH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_BOTH_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/algorithm/detail/binary_fold.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function,
	typename State,
	typename MakeIterator
>
class unwrap_binary_both
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_binary_both
	);
public:
	unwrap_binary_both(
		Function const &_function,
		State _state,
		MakeIterator const &_make_iterator
	)
	:
		function_(
			_function
		),
		state_(
			_state
		),
		make_iterator_(
			_make_iterator
		)
	{
	}

	typedef
	State
	result_type;

	template<
		typename View1,
		typename View2
	>
	result_type
	operator()(
		View1 const &_view1,
		View2 const &_view2
	) const
	{
		return
			mizuiro::image::algorithm::detail::binary_fold(
				function_,
				state_,
				_view1,
				_view2,
				make_iterator_
			);
	}
private:
	Function const &function_;

	State state_;

	MakeIterator const &make_iterator_;
};

}
}
}
}

#endif
