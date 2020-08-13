#include "Comparators/Comparators.hpp"
#include <vector>

namespace pc {
namespace Comparators {

template<>
bool is_same(const std::vector<int>& a, const std::vector<int>& b)
{
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

}
}