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


int prim_minimum_spanning_tree(const std::vector<std::vector<std::pair<int, int>>>& g)
{
    int n = g.size();
    int res = 0;
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<char> mark(n, 0);

    pq.push(std::make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (mark[u] == 1)  {
            continue;
        }
        mark[u] = 1;
        res += w;

        for (const auto& node : g[u]) {
            if (mark[node.first] == 1) {
                continue;
            }
           
            pq.push(std::make_pair(node.second, node.first)); 
        }
    }

    return  res;


    ///TODO fix this
}


}
}