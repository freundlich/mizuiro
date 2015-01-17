//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MIN_CHANNEL_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MIN_CHANNEL_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/copy_or_min_channel.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Src,
	typename Dest
>
class copy_or_min_channel_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		copy_or_min_channel_function
	);
public:
	copy_or_min_channel_function(
		Src const &_src,
		Dest &_dest
	)
	:
		src_(
			_src
		),
		dest_(
			_dest
		)
	{
	}

	typedef
	void
	result_type;

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		mizuiro::color::conversion::detail::copy_or_min_channel(
			_channel,
			src_,
			dest_
		);
	}
private:
	Src const &src_;

	Dest &dest_;
};

}
}
}
}

#endif
