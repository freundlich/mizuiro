#ifndef MIZUIRO_COLOR_LAYOUT_BGRA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_BGRA_HPP_INCLUDED

#include <mizuiro/color/layout/additive.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef additive<
	boost::mpl::vector4<
		channel::blue,
		channel::green,
		channel::red,
		channel::alpha
	>
> bgra;

}
}
}

#endif
