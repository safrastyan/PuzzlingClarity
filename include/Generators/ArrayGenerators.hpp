#pragma once

#include <vector>

namespace pc {
namespace Generators {

/** 
 * @brief Generates and returns an array of size n with numbers from 1 to n included
 * @param n up to the number n
 * @param mulitplier multiplies all elements by multiplier, default = 1
 **/
std::vector<int> ArrayFrom1toN(int n, int multiplier=1);


}
}
