#ifndef MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>

namespace mizuiro
{
namespace image
{

// TODO: make this work with linear_iterator as well!

namespace detail
{
template<
	typename Format,
	typename Constness
>
typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const
dim_size(
	pitch_iterator<
		Format,
		Constness
	> const &it,
	typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const i
)
{
	typedef typename 
		pitch_iterator<
			Format,
			Constness
		>::dim_type::size_type size_type;

	if (i == static_cast<size_type>(it.dim().static_size-1))
		return static_cast<size_type>(1);
	
	return 
		it.dim()[i]*dim_size(it,static_cast<size_type>(i-1))+it.pitch()[i];
}

template<
	typename Format,
	typename Constness
>
typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const
numerator(
	pitch_iterator<
		Format,
		Constness
	> const &it,
	typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const i
)
{
	if (i == it.dim().static_size)
		return it.data() - it.root_data();
	return 
		numerator(
			it,
			static_cast
			<
				typename pitch_iterator
				<
					Format,
					Constness
				>::dim_type::size_type
			>
			(
				i+1)
			) 
			% 
			dim_size
			(
				it,
				i
			);
}

template<
	typename Format,
	typename Constness
>
typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const
denominator(
	pitch_iterator<
		Format,
		Constness
	> const &it,
	typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const i
)
{
	return 
		dim_size
		(
			it,
			static_cast
			<
				typename pitch_iterator
				<
					Format,
					Constness
				>::dim_type::size_type
			>
			(
				i-1
			)
		);
}
}

template<
	typename Format,
	typename Constness
>
typename Format::dim_type const
iterator_position(
	pitch_iterator<
		Format,
		Constness
	> const &it
)
{
	typename Format::dim_type d;
	for (typename pitch_iterator<Format,Constness>::dim_type::size_type i = 0; i < it.dim().static_size; ++i)
		d[i] = detail::numerator(it,i)/detail::denominator(it,i);
	return d;
}

}
}

#endif
