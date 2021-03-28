#include "algo/Graphs.hpp"

#include <vector>
#include <queue>

namespace pc {
namespace algo {


int shortest_path(const Graph& g, int src, int dst)
{
    std::vector<char> mark(g.size(), 0);
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(src, 0));
    mark[src] = 1;
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        for (auto node: g[f.first]) {
            if (mark[node] == 1) {
                continue;
            }
            if (node == dst) {
                return f.second + 1;
            }
            q.push(std::make_pair(node, f.second + 1));
            mark[node] = 1;
        }
    }
    return -1;
}

}
}