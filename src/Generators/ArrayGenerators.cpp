#include "Generators/ArrayGenerators.hpp"

namespace pc {
namespace Generators {

std::vector<int> ArrayFrom1toN(int n, int multiplier)
{
    std::vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = i + 1;
        res[i] *= multiplier;
    }
    return res;
}    

}
}