#include "algo/Sets.hpp"

#include <iostream>

int main()
{
    std::vector<int> a{1, 2, 3, 4, 5 , 6, 7, 8};
    auto res = pc::algo::k_almost_equal_subsets(a, 3, true);
    std::cout << "Best subsets are " << std::endl;
    for (const auto& x: res) {
        for (auto y: x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}