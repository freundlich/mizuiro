#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_TERNARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_TERNARY_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Fun
>
struct transform_ternary {
	typedef void result_type;

	explicit transform_ternary(
		Fun const &fun
	)
	:
		fun(fun)
	{}

	template<
		typename Source1,
		typename Source2,
		typename Dest
	>
	result_type
	operator()(
		Source1 const &source1,
		Source2 const &source2,
		Dest const &dest
	) const
	{
		this->fun(
			source1,
			source2,
			dest
		);
	}
private:
	Fun const &fun;
};

}
}
}
}

#endif
