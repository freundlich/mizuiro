//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_BRESENHAM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_BRESENHAM_HPP_INCLUDED

#include <mizuiro/color/operators.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/make_signed.hpp>
#include <algorithm>
#include <cstdlib>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template
<
	typename View,
	typename Color
>
void
bresenham
(
	View const &v,
	typename View::dim const &start,
	typename View::dim const &end,
	Color const &c0,
	Color const &c1
)
{
	typedef typename
	boost::make_signed
	<
		typename View::dim::value_type
	>::type
	int_type;

	int_type x0 = static_cast<int_type>(start[0]);
	int_type y0 = static_cast<int_type>(start[1]);
	int_type x1 = static_cast<int_type>(end[0]);
	int_type y1 = static_cast<int_type>(end[1]);

	bool const steep = std::abs(y1 - y0) > std::abs(x1 - x0);
	if (steep){
		std::swap(x0, y0);
		std::swap(x1, y1);
	}
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int_type const deltax = x1 - x0;
	int_type const deltay = std::abs(y1 - y0);
	int_type error = deltax / 2;
	int_type y = y0;
	int_type const ystep = (y0 < y1) ? 1 : -1;

	double length =
			static_cast<double>(x1 - x0) *
			static_cast<double>(x1 - x0) +
			static_cast<double>(y1 - y0) *
			static_cast<double>(y1 - y0);

	for (int_type x = x0; x <= x1; ++x)
	{
		double pos =
				static_cast<double>(x - x0) *
				static_cast<double>(x - x0) +
				static_cast<double>(y - y0) *
				static_cast<double>(y - y0);
		double t = pos / length;

		Color c = t * c1 + (1.0 - t) * c0;

		if (steep)
			v[typename View::dim(static_cast<typename View::dim::value_type>(y), static_cast<typename View::dim::value_type>(x))] = c;
		else
			v[typename View::dim(static_cast<typename View::dim::value_type>(x), static_cast<typename View::dim::value_type>(y))] = c;
		error -= deltay;
		if (error < 0)
		{
			y += ystep;
			error += deltax;
		}
	}
}

}
}
}

#endif
