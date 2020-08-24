#include "algo/SlidingWindows.hpp"
#include "Generators/ArrayGenerators.hpp"
#include "Time/Time.hpp"
#include "Comparators/Comparators.hpp"

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace pc::algo;
using namespace pc::Time;

int main()
{
    std::cout << "First trying with sliding window, n = 1000000, k = 1000" << std::endl;
    int n = 1000000;
    int k = 1000;
    push();
    auto arr = pc::Generators::random_array(n);
    auto res1 = sliding_window_sums(arr,  k);
    pop("Total time ");
    
    std::cout << "Now trying with accumulate " << std::endl;
    push();
    std::vector<int> res;
    for (int i = 0; i + k <= arr.size(); ++i) {
        res.push_back(std::accumulate(arr.begin() + i, arr.begin() + i + k,  0));
        
    }
    pop("Total time ");

    assert(pc::Comparators::is_same(res1, res));
    return 0;

}