//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/metal/is_set.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/init/detail/contains_channel.hpp>
#include <mizuiro/color/init/detail/set_channel.hpp>
#include <mizuiro/color/init/detail/to_channel_type.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/types/static_channels.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Format,
	typename Vector
>
inline
void
assign_object(
	mizuiro::color::object<
		Format
	> &_object,
	mizuiro::color::init::detail::values<
		Vector
	> const &_init
)
{
	typedef
	metal::as_list<
		Vector
	>
	color_types;

	static_assert(
		metal::all_of<
			mizuiro::color::types::static_channels<
				Format
			>,
			metal::bind<
				metal::trait<
					mizuiro::color::init::detail::contains_channel
				>,
				metal::always<
					color_types
				>,
				metal::_1
			>
		>::value,
		"Forgotten channel in initialization"
	);

	static_assert(
		fcppt::metal::is_set<
			metal::transform<
				metal::lambda<
					mizuiro::color::init::detail::to_channel_type
				>,
				color_types
			>
		>::value,
		"Duplicate channel initialization"
	);

	fcppt::algorithm::loop(
		_init.get(),
		[
			&_object
		](
			auto const &_value
		)
		{
			mizuiro::color::init::detail::set_channel(
				_object,
				_value
			);
		}
	);
}

}
}
}
}

#endif
