//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/compare_channels.hpp>
#include <mizuiro/color/access/convert.hpp>
#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/access/is_last_channel.hpp>
#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/convert_static.hpp>
#include <mizuiro/color/format_store.hpp>
#include <mizuiro/color/is_homogenous_static.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/size.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Format,
	typename Channel
>
struct channel_index<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		color::format_store<Format> const &, 
		Channel const &
	)
	{
		return
			mizuiro::detail::index_of<
				typename Format::layout::order,
				Channel
			>::value;
	}
};

template<
	typename Format
>
struct layout<
	Format,	
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	typename Format::layout::order const
	execute(
		color::format_store<Format> const &
	)
	{
		return typename Format::layout::order();
	}
};

template<
	typename Format,
	typename Channel
>
struct is_last_channel<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	bool
	execute(
		color::format_store<Format> const &, 
		Channel const &
	)
	{
		return
			mizuiro::detail::index_of<
				typename Format::layout::order,
				Channel
			>::value + 1
			==
			boost::mpl::size<
				typename Format::layout::order
			>::value;
	}
};

template<
	typename Format,
	typename Channel
>
struct compare_channels<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	template<
		typename OtherChannel
	>
	static
	bool
	execute(
		color::format_store<Format> const &,
		OtherChannel const &
	)
	{
		return
			boost::is_same<
				Channel,
				OtherChannel
			>::value;
	}
};

template<
	typename Format,
	typename StaticChannel
>
struct has_channel<
	Format,
	StaticChannel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	bool
	execute(
		color::format_store<Format> const &
	)
	{
		return
			boost::mpl::contains<
				typename Format::order,
				StaticChannel
			>::value;
	}
};

template<
	typename SourceFormat,
	typename DestFormat
>
struct convert<
	SourceFormat,
	DestFormat,
	typename boost::enable_if<
		boost::mpl::and_<
			mizuiro::color::is_homogenous_static<
				SourceFormat
			>,
			mizuiro::color::is_homogenous_static<
				DestFormat
			>
		>
	>::type
>
{
	template<
		typename Source
	>
	static
	color::object<
		DestFormat
	> const
	execute(
		Source const &_source,
		color::format_store<DestFormat> const &
	)
	{
		return
			color::convert_static::convert<
				DestFormat
			>(
				_source
			);
	}
};

}
}
}

#endif