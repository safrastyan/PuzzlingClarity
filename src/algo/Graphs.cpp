#include "algo/Graphs.hpp"

#include <limits>
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

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& a, int src)
{
    int n = a.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<char> mark(n, 0);
    dist[src] = 0;
    mark[src] = 1;
    std::priority_queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, src));

    while (!q.empty()) {
        auto elem = q.top();
        q.pop();
        int old_dist = -elem.first;
        int node = elem.second;
        

        for (int i = 0; i < a[node].size(); ++i) {
            int new_node = a[node][i].first;
            int new_dist = a[node][i].second;
            if (mark[new_node] == 1) {
                continue;
            }
            if (new_dist + old_dist >= dist[new_node]) {
                continue;
            }
            dist[new_node] = new_dist + old_dist;
            q.push(std::make_pair(-(new_dist + old_dist), new_node));
            mark[new_node] = 1;
        }
    }
    return dist;
}

std::vector<std::vector<int>> floyd_warshall(const std::vector<std::vector<std::pair<int, int>>>& a)
{
    int n = a.size();
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == std::numeric_limits<int>::max() || dist[i][k] == std::numeric_limits<int>::max()) {
                    continue;
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

}
}