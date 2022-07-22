#include "io/io.hpp"
#include "Time/Time.hpp"
#include "Generators/ArrayGenerators.hpp"
#include "Generators/NumberGenerators.hpp"
#include "algo/SegmentTree.hpp"

#include <algorithm>

using namespace pc::algo;
using namespace pc::Generators;
using namespace pc::Time;

int main()
{
    int n = 100000;
    int t = 1000;
    auto data = random_array(n);
    
    auto min = range_minimum_query(data);
    
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < t; ++i) {
        int left = random_number(0, n - 1);
        int right = random_number(0, n -1);
        if (left > right) {
            std::swap(left, right);
        }
        p.emplace_back(left, right);
    }

    push();
    for (auto& pp: p) {
        auto res = std::min_element(data.begin() + pp.first, data.begin() + pp.second + 1);
    }
    pop("Linear took ");
    
    push();
    for (auto& pp: p) {
        auto res = min.query(pp.first, pp.second);
    }
    pop("Segment Tree took");
    return 0;

}