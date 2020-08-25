///This file contains common tasks which require dynamic programming approacch

#include <vector>

namespace pc {
namespace algo {


/**
 * Problem Statement:
 * Calculate the number of unique sequences of 0s and 1s where there are no consecutive 1s
 **/
int zeros_and_ones(int n);

/**
 * @brief Knapsack problem. Only the weights of the elements. Each item can be used infite times 
 * @param elems weights of the elements
 * @param k the maximum capacity of the knapsack 
 **/
int knapsack_infinte_elements(const std::vector<int>& elems, int k);

/**
 * @brief Knapsack classic problem. Items weights and values. One item used only once. Maximum value possible
 * @param elems array of pairs, first element the weight, second the value
 * @param k the maximum capacity of the knapsack, weightwise
 **/
int knapsack_classic(const std::vector<std::pair<int, int>>& elems, int k);

}
}