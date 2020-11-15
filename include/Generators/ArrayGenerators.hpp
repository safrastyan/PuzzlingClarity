#pragma once

#include <vector>
#include <limits>

namespace pc {
namespace Generators {

/** 
 * @brief Generates and returns an array of size n with numbers from 1 to n included
 * @param n up to the number n
 * @param mulitplier multiplies all elements by multiplier, default = 1
 **/
std::vector<int> array_from_1_to_n(int n, int multiplier=1);

/**
 * @brief generate random array of integers
 * @param n the size of the desired array
 * @param range_left the lowest value in the varray. Default 0
 * @param range_right the highest value in the array. Default numer_limits max of int
 **/
std::vector<int> random_array(int n, int range_left = 0, int range_right = std::numeric_limits<int>::max());

}
}
