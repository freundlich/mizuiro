#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/detail/extract_channel.hpp>

template<
	typename Layout,
	typename Constness
>
mizuiro::color::proxy<Layout, Constness>::proxy(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Layout,
	typename Constness
>
template<
	typename Channel
>
void
mizuiro::color::proxy<Layout, Constness>::set(
	typename detail::channel_ref<
		layout,
		Channel,
		mizuiro::detail::const_tag
	>::type ref
)
{
	detail::extract_channel<
		layout,
		Channel,
		mizuiro::detail::nonconst_tag
	>::execute(
		data_	
	) = ref;
}

template<
	typename Layout,
	typename Constness
>
template<
	typename Channel
>
typename mizuiro::color::detail::channel_ref<
	Layout,
	Channel,
	mizuiro::detail::const_tag
>::type
mizuiro::color::proxy<Layout, Constness>::get() const
{
	return detail::extract_channel<
		layout,
		Channel,
		mizuiro::detail::const_tag
	>::execute(
		data_
	);
}

#endif
