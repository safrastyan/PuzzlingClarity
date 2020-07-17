#include "Utils/Distanes.hpp"

#include <cmath>

namespace pc {
namespace Utils {

int cross_abs_dif_sum(const std::vector<int>& a)
{
    int res = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            res += std::abs(a[i] - a[j]);
        }
    }
    return res;
}

}
}
