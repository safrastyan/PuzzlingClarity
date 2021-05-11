#pragma once

#include <vector>

namespace pc {
namespace algo {

/** @brief helper for merge sort. merges the portion of the array assuming that the inrevals [left; middle] and [middle + 1; right] are sorted. Merges this 2 togehter, while not touching the rest of the array
 * @param arr source array
 * @param left beginning of the interested interval
 * @param middle of the interested interval
 * @param right end of the interested interval
 **/
void merge(std::vector<int>& arr, int left, int middle, int right);

/// sort the array using bubble sort. Complexity O(N^2)
std::vector<int> bubble_sort(const std::vector<int>& arr);

/**
 * @brief sort the array using bucket sort. O(n) for small maximum elements. Works only on natural numbers
 * @param arr array to be sorted
 * @param max_elemenet the size of the buckets to allocate aka the maximum possible element in the array
 **/
std::vector<int> bucket_sort(const std::vector<int>& arr, int max_element);


/// sort the array using merge sort. Complexity O(NlogN)
std::vector<int> merge_sort(const std::vector<int>& arr);


}
}
