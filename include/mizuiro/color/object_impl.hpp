//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/default_init_fwd.hpp>
#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/format/base_impl.hpp>
#include <mizuiro/color/format/store_impl.hpp>
#include <mizuiro/color/init/detail/assign_object.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
mizuiro::color::object<
	Format
>::object(
	mizuiro::no_init const &,
	format_store_type const &_format
)
:
	base(
		_format
	)
	// FIXME: Preparing data requires special cases
{
}

MIZUIRO_DETAIL_POP_WARNING

template<
	typename Format
>
mizuiro::color::object<
	Format
>::object(
	mizuiro::default_init const &,
	format_store_type const &_format
)
:
	base(
		_format
	),
	data_() // TODO: Should we rely on the default ctor?
{
}

template<
	typename Format
>
mizuiro::color::object<
	Format
>::object(
	object const &_other
)
:
	base(
		_other.format_store()
	),
	data_(
		_other.data_
	)

{
}

template<
	typename Format
>
template<
	typename Other
>
mizuiro::color::object<
	Format
>::object(
	Other const &_other,
	typename std::enable_if<
		mizuiro::color::is_color<
			Other
		>::value
	>::type *
)
:
	base(
		_other.format_store()
	),
	// FIXME: Preparing data requires special cases
	data_()
{
	proxy(
		data_.data(),
		this->format_store()
	) = _other;
}

template<
	typename Format
>
template<
	typename Vector
>
mizuiro::color::object<
	Format
>::object(
	mizuiro::color::init::detail::values<
		Vector
	> const &_init,
	format_store_type const &_format
)
:
	base(
		_format
	),
	// FIXME: Preparing data requires special cases
	data_()
{
	mizuiro::color::init::detail::assign_object(
		*this,
		_init
	);
}

template<
	typename Format
>
template<
	typename Channel
>
void
mizuiro::color::object<
	Format
>::set(
	Channel const &_channel,
	mizuiro::color::types::channel_value<
		format,
		Channel
	> const &_ref
)
{
	this->make_proxy().set(
		_channel,
		_ref
	);
}

template<
	typename Format
>
template<
	typename Channel
>
mizuiro::color::types::channel_reference<
	typename
	mizuiro::color::object<
		Format
	>::access,
	typename
	mizuiro::color::object<
		Format
	>::format,
	Channel,
	mizuiro::const_tag
>
mizuiro::color::object<
	Format
>::get(
	Channel const &_channel
) const
{
	return
		this->make_const_proxy().get(
			_channel
		);
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<
	Format
>::data()
{
	return
		this->make_proxy().data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<
	Format
>::data() const
{
	return
		this->make_const_proxy().data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<
	Format
>::data_end()
{
	return
		this->make_proxy().data_end();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<
	Format
>::data_end() const
{
	return
		this->make_const_proxy().data_end();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::format_store_type const
mizuiro::color::object<
	Format
>::format_store() const
{
	return
		this->format_store_base();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::proxy const
mizuiro::color::object<
	Format
>::make_proxy()
{
	return
		proxy(
			data_.data(),
			this->format_store()
		);
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_proxy const
mizuiro::color::object<
	Format
>::make_const_proxy() const
{
	return
		const_proxy(
			data_.data(),
			this->format_store()
		);
}

#endif
