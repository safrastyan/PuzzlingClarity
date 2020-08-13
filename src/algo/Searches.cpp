#include "algo/Searches.hpp"

namespace pc {
namespace algo {

int binary_search(const std::vector<int>& a, int elem)
{
    int p = 0;
    int q = a.size() - 1;
    while (q - p > 1) {
        int mid = (p + q) / 2;
        if (a[mid] == elem) {
            return mid;
        }
        if (a[mid] < elem) {
            p = mid;
        } else {
            q = mid;
        }
    }
    if (a[p] == elem) {
        return p;
    }
    return a[q] == elem ? q : -1;
}

}
}