//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_PREPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_PREPARE_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/format/store.hpp>
#include <mizuiro/image/prepare_store_units.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Access,
	typename ImageFormat,
	typename Function
>
class prepare
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		Function
	);
public:
	prepare(
		mizuiro::image::format::store<
			ImageFormat
		> const &_format_store,
		Function const &_function
	)
	:
		format_store_(
			_format_store
		),
		function_(
			_function
		)
	{
	}

	typedef
	void
	result_type;

	template<
		typename Dest
	>
	result_type
	operator()(
		Dest const &_dest
	) const
	{
		mizuiro::image::prepare_store_units<
			Access
		>(
			format_store_,
			_dest
		);

		function_(
			_dest
		);
	}

	template<
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Src const &_src,
		Dest const &_dest
	) const
	{
		mizuiro::image::prepare_store_units<
			Access
		>(
			format_store_,
			_dest
		);

		function_(
			_src,
			_dest
		);
	}
private:
	mizuiro::image::format::store<
		ImageFormat
	> const &format_store_;

	Function const &function_;
};

}
}
}
}

#endif