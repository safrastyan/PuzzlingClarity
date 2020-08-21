#pragma once

#include <vector>

namespace pc {
namespace Generators {

/** 
 * @brief Generates and returns an array of size n with numbers from 1 to n included
 * @param n up to the number n
 * @param mulitplier multiplies all elements by multiplier, default = 1
 **/
std::vector<int> array_from_1_to_n(int n, int multiplier=1);

/// uniform random array
std::vector<int> random_array(int n);

}
}
