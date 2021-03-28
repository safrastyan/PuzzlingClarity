#include "Generators/GraphGenerators.hpp"
#include "Generators/NumberGenerators.hpp"

#include <algorithm>

namespace pc {
namespace Generators {

std::vector<std::vector<int>> graph(int nodes, int edges, bool directed)
{
    std::vector<std::vector<int>> g(nodes + 1);

    int all_edges = (nodes * (nodes - 1)) / 2;
    std::vector<std::pair<int, int>> all;
    for (int i = 1; i <= nodes; ++i) {
        for (int j = i + 1; j <= nodes; ++j) {
            all.push_back(std::make_pair(i, j));
        }
    }
    std::srand(time(0));
    std::random_shuffle(all.begin(), all.end());
    for (int i = 0; i < edges; ++i) {
        auto x = all[i].first;
        auto y = all[i].second;
        g[x].push_back(y);
        if (!directed) {
            g[y].push_back(x);
        }
    }
    return g;
}


}
}