#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

template<
	typename Layout
>
mizuiro::color::object<Layout>::object()
:
	data_()
{}

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN(\
	z,\
	n,\
	text\
)\
set<\
	typename T##n::channel\
>(\
	t##n.value()\
);

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL(\
	z,\
	n,\
	text\
)\
template<\
	typename Layout\
>\
template<\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
mizuiro::color::object<Layout>::object(\
	BOOST_PP_ENUM_BINARY_PARAMS(\
		BOOST_PP_INC(n),\
		T,\
		const &t\
	)\
)\
:\
	data_()\
{\
	BOOST_PP_REPEAT(\
		BOOST_PP_INC(n),\
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN,\
		t\
	)\
}

BOOST_PP_REPEAT(
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE,
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL,
	void
)

#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL
#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN

template<
	typename Layout
>
template<
	typename Channel
>
void
mizuiro::color::object<Layout>::set(
	typename detail::channel_ref<
		typename proxy::layout,
		Channel,
		mizuiro::detail::const_tag
	>::type const ref
)
{
	proxy(
		data_.data()
	).set<
		Channel
	>(
		ref
	);
}

template<
	typename Layout
>
template<
	typename Channel
>
typename mizuiro::color::detail::channel_ref<
	typename mizuiro::color::object<Layout>::const_proxy::layout,
	Channel,
	mizuiro::detail::const_tag
>::type
mizuiro::color::object<Layout>::get() const
{
	return const_proxy(
		data_.data()
	).get<
		Channel
	>();
}

#endif