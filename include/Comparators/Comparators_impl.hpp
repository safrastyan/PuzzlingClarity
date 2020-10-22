#pragma once

#include <vector>

namespace pc {
namespace Comparators {

template<typename T, typename P>
bool is_same(const std::vector<T>& a, const std::vector<P>& b)
{
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i  < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

}
}