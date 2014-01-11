//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/format/argument.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename Format,
	typename Constness
>
class linear_view
:
	private
	mizuiro::image::format::base<
		Format
	>::type
{
	typedef
	typename
	mizuiro::image::format::base<
		Format
	>::type
	format_base;
public:
	typedef
	Access
	access;

	typedef
	Format
	format;

	typedef
	Constness
	constness;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		constness
	>
	pointer;

	typedef
	mizuiro::image::types::reference<
		access,
		format,
		constness
	>
	reference;

	typedef
	mizuiro::image::linear_iterator<
		access,
		format,
		constness
	>
	iterator;

	typedef
	typename
	format::dim
	dim;

	typedef
	mizuiro::image::bound<
		dim::static_size,
		typename
		dim::value_type
	>
	bound_type;

	typedef
	typename
	format::pitch pitch_type;

	linear_view(
		dim const &,
		pointer data,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	linear_view(
		linear_view const &
	);

	template<
		typename OtherConstness
	>
	explicit
	linear_view(
		mizuiro::image::linear_view<
			access,
			format,
			OtherConstness
		> const &
	);

	dim const &
	size() const;

	pitch_type const
	pitch() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	reference
	operator[](
		dim const &
	) const;

	pointer
	data() const;

	format_store_type const
	format_store() const;
private:
	dim size_;

	pointer data_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
