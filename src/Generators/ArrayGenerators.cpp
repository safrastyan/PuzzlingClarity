#include "Generators/ArrayGenerators.hpp"

#include <random>
#include <algorithm>
#include <functional>

namespace pc {
namespace Generators {

std::vector<int> array_from_1_to_n(int n, int multiplier)
{
    std::vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = i + 1;
        res[i] *= multiplier;
    }
    return res;
}    

std::vector<int> random_array(int n, int range_left, int range_right)
{
    
    std::random_device r;
    std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937       eng(seed);

    std::uniform_int_distribution<int> dist;
    std::vector<int> v(n);

    std::generate(begin(v), end(v), std::bind(dist, eng));

    int range_len = range_right - range_left;

    for (int i = 0; i < v.size(); ++i) {
        v[i] = v[i] % range_len + range_left;    
    }
    
    return v;
}


}
}