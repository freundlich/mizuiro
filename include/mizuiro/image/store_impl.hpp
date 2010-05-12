#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/raw_container_impl.hpp>

template<
	typename Format,
	typename Access 
>
mizuiro::image::store<Format, Access>::store()
:
	dim_(
		dim_type::null()
	),
	data_()
{}

template<
	typename Format,
	typename Access 
>
mizuiro::image::store<Format, Access>::store(
	dim_type const &dim_
)
:
	dim_(
		dim_
	),
	data_(
		dim_.content()
		* Format::image_format::color_format::element_count
	)
{}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::pointer
mizuiro::image::store<Format, Access>::data()
{
	return data_.data();
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::const_pointer
mizuiro::image::store<Format, Access>::data() const
{
	return data_.data();
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::view_type const
mizuiro::image::store<Format, Access>::view()
{
	return view_type(
		dim(),
		data()
	);
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::const_view_type const
mizuiro::image::store<Format, Access>::view() const
{
	return const_view_type(
		dim(),
		data()
	);
}
template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::dim_type const &
mizuiro::image::store<Format, Access>::dim() const
{
	return dim_;
}

#endif
