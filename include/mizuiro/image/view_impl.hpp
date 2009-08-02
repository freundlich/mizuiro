#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/image/iterator_pair_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <stdexcept>

template<
	typename Format,
	typename Constness
>
mizuiro::image::view<Format, Constness>::view(
	dim_type const &dim_,
	pointer const data_
)
:
	dim_(dim_),
	data_(data_),
	sub_data_(data_),
	pitch_(pitch_type::null())
{}

template<
	typename Format,
	typename Constness
>
mizuiro::image::view<Format, Constness>::view(
	dim_type const &dim_,
	pointer const data_,
	pointer const sub_data_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	sub_data_(sub_data_),
	pitch_(pitch_)
{}

template<
	typename Format,
	typename Constness
>
mizuiro::image::view<Format, Constness>::view(
	view<
		Format,
		mizuiro::detail::nonconst_tag
	> const &other
)
:
	dim_(other.dim()),
	data_(other.data()),
	sub_data_(other.sub_data()),
	pitch_(other.pitch())
{}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::dim_type const &
mizuiro::image::view<Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator const
mizuiro::image::view<Format, Constness>::begin() const
{
	return is_linear()
		? iterator(
			linear_begin()
		)
		: iterator(
			pitch_begin()	
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator const
mizuiro::image::view<Format, Constness>::end() const
{
	return begin() + dim().content();
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator_pair const
mizuiro::image::view<Format, Constness>::range() const
{
	return is_linear()
		? iterator_pair(
			linear_iterator_pair(
				linear_begin(),
				linear_end()
			)
		)
		: iterator_pair(
			pitch_iterator_pair(
				pitch_begin(),
				pitch_end()
			)
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::reference
mizuiro::image::view<Format, Constness>::operator[](
	dim_type const &index
) const
{
	return *move_iterator(
		*this,
		index
	);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::reference
mizuiro::image::view<Format, Constness>::at(
	dim_type const &index
) const
{
	for(
		size_type i = 0;
		i < dim_type::static_size;
		++i
	)
		// TODO: replace this with our own exception and add a better error message!
		if(index[i] >= dim()[i])
			throw std::range_error("view::at out of range");
	
	return (*this)[index];
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pointer
mizuiro::image::view<Format, Constness>::data() const
{
	return data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pointer
mizuiro::image::view<Format, Constness>::sub_data() const
{
	return sub_data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pitch_type const &
mizuiro::image::view<Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Format,
	typename Constness
>
bool
mizuiro::image::view<Format, Constness>::is_linear() const
{
	return pitch_ == pitch_type::null();
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::linear_iterator const
mizuiro::image::view<Format, Constness>::linear_begin() const
{
	return linear_iterator(
		data_
	);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::linear_iterator const
mizuiro::image::view<Format, Constness>::linear_end() const
{
	return linear_begin() + dim().content();
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pitch_iterator const
mizuiro::image::view<Format, Constness>::pitch_begin() const
{
	return pitch_iterator(
		dim(),
		sub_data_,
		data_,
		pitch_ 
	);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pitch_iterator const
mizuiro::image::view<Format, Constness>::pitch_end() const
{
	return pitch_begin() + dim().content();
}

#endif
