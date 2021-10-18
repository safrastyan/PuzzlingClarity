#pragma once

#include <vector>
#include <cmath>

namespace pc {
namespace Comparators {

template<typename T, typename U>
bool is_same(const T&, const U&);

/// checks if the doubles are the same with epsilon
bool same_double(double x, double y)
{
    return std::abs(x - y) < 0.000001;  ///TODO this epsilon might be tricky
}

}
}

#include "Comparators/Comparators_impl.hpp"