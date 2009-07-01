#ifndef MIZUIRO_IMAGE_STRIDE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_STRIDE_POINTER_HPP_INCLUDED

//#include <mizuiro/image/stride_pointer_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/difference_type.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename T,
	mizuiro::size_type Stride
>
class stride_pointer {
public:
	stride_pointer(
		T *
	);

	stride_pointer &
	operator+=(
		difference_type
	);

	stride_pointer &
	operator-=(
		difference_type
	);

	stride_pointer &
	operator++();

	stride_pointer &
	operator--();
private:
	T *base_;
};

template<
	typename T,
	mizuiro::size_type Stride
>
difference_type
operator-(
	stride_pointer<T, Stride> const &,
	stride_pointer<T, Stride> const &
);

template<
	typename T,
	mizuiro::size_type Stride
>
bool
operator==(
	stride_pointer<T, Stride> const &,
	stride_pointer<T, Stride> const &
);

}
}

#endif
