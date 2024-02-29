#pragma once

#include <queue>

namespace pc {
namespace algo {

template<typename T> 
inline std::vector<std::vector<T>> fill_connected_component_t(const std::vector<std::vector<T>>& grid, int row, int col, const T& elem, bool diagonal)
{
    auto g = grid;
    if (grid[row][col] == elem) {
        return g;
    }
    auto look_for = grid[row][col];
    int r = g.size();
    int c = g[0].size();
    
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(row, col));
    
    g[row][col] = elem;
    
    static constexpr int pr[] = {-1, 1, 0, 0};
    static constexpr int pc[] = {0, 0, -1, 1};
    
    static constexpr int prd[] = {-1, 1, 0, 0, 1, 1, -1, -1};
    static constexpr int pcd[] = {0, 0, -1, 1, 1, -1, 1, -1};
    
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for (int i = 0; i < (diagonal ? 8 : 4); ++i) {
            int nr = cr + diagonal ? prd[i] : pr[i];
            int nc = cc + diagonal ? pcd[i] : pc[i];
            if (nr < r && nc < c && nr >= 0 && nc >= 0  && g[nr][nc] == look_for) {
                g[nr][nc] = elem;
                q.push(std::make_pair(nr, nc));
            }
        }
    }
    return g;
}

}
}
