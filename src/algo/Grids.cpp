#include "algo/Grids.hpp"

#include <queue>
#include <cassert>

namespace pc {
namespace algo {


Grid rotate_90_clockwise(const Grid& grid)
{
    ///supports square for now
    auto res = grid;
    int r = grid.size();
    int c = grid[0].size();
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            res[j][c - i - 1] = grid[i][j];
        }
    }
    return res;
}

Grid rotate_180_clockwise(const Grid& grid)
{
    ///supports square for now
    
    Grid res = grid;
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            res[r - i - 1][c - j - 1] = grid[i][j];
        }
    }
    return res;
}


Grid rotate_270_clockwise(const Grid& grid)
{
    ///supports square for now
    Grid res = grid;
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            res[r - j - 1][i] = grid[i][j];
        }
    }
    return res;
}

Grid mirror_horizontal(const Grid& grid)
{
    ///supports square for now
    Grid res = grid;
    int r = grid.size();
    int c = grid[0].size();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            res[i][c - j - 1] = grid[i][j];
        }
    }
    return res;
}

Coords connected_component(const Grid& g, int x, int y)
{ 
    char ch = g[x][y];
    int r = g.size();
    int c = g[0].size();
    std::vector<std::vector<char>> visited(r, std::vector<char>(c, 0));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> res;
    q.push(std::make_pair(x, y));
    res.push_back(std::make_pair(x, y));
    visited[x][y] = 1;
    static int px[] = {-1, 1, 0, 0};
    static int py[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + px[i];
            int ny = cy + py[i];
            if (nx < r && ny < c && nx >= 0 && ny >= 0 && visited[nx][ny] == 0 && g[nx][ny] == ch) {
                visited[nx][ny] = 1;
                q.push(std::make_pair(nx, ny));
                res.push_back(std::make_pair(nx, ny));
            }
        }
    }
    return res;
}

void fill_connected_component(Grid& g, int x, int y, char with)
{
    auto coords = connected_component(g, x, y);
    for (const auto& p: coords) {
        g[p.first][p.second] = with;
    }
}

std::ostream& operator << (std::ostream& o, const Grid& g)
{
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[0].size(); ++j) {
            o << g[i][j];
        }
        o << std::endl;
    }
    return o;
}

bool operator == (const Grid& g1, const Grid& g2)
{
    if (g1.size() != g2.size()) {
        return false;
    }
    for (int i = 0; i < g1.size(); ++i) {
        if (g1[i].size() != g2.size()) {
            return false;
        }
        for (int j = 0; j < g1[i].size(); ++j) {
            if (g1[i][j] != g2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

}
}
