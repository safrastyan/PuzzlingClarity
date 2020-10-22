#include "Comparators/Comparators.hpp"
#include <vector>

namespace pc {
namespace Comparators {

template<>
bool is_same(const std::vector<std::vector<char>>& a, const std::vector<std::vector<char>>& b)
{
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
       // if (a[i].size() != b[i].size())
    }
}


}
}