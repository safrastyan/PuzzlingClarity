#pragma once 

#include <vector>

namespace pc {
namespace algo {

/// uses bitmask on the number of elements and generates all the subsets. Be careful, very consuming process
template<typename T>
std::vector<std::vector<T>> generate_all_subsets(const std::vector<T>&);

}
}

#include "Sets_impl.hpp"
