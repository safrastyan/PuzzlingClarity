#pragma once

#include <vector>

namespace pc {
namespace Games {

/// this function plays the specified game specified number of times and returns a history

template<typename G>
std::vector<typename G::State> collect(G g, int num)
{
    std::vector<typename G::State> data;
    for (int i = 0; i < num; ++i) {
        data.push_back(g.play());
    }
    return data;
}

}
}