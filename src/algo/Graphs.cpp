#include "algo/Graphs.hpp"

#include <queue>
#include <cassert>


namespace pc {
namespace algo {

bool operator == (const Grid& g1, const Grid& g2)
{
    if (g1.r != g2.r || g1.c != g2.c) {
        return false;
    }

    for (int i = 0; i < g1.r; ++i) {
        for (int j = 0; j < g1.c; ++j) {
            if (g1.data[i][j] != g2.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

Grid::Grid(int r_, int c_): data(r_, std::vector<char>(c_))
                          , r(r_)
                          , c(c_)
{}

Grid::Grid(int r_, int c_, char fill_with): data(r_, std::vector<char>(c_, fill_with))
                                          , r(r_)
                                          , c(c_)
{}

Grid::Grid(const std::vector<std::vector<char>>& d): data(d)
                                                   , r(d.size())
                                                   , c(d[0].size())
{}                                                         

Grid Grid::rotate_90_clockwise() const
{
    ///supports square for now
    assert(r == c);
    Grid g(data);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            g.data[j][c - i - 1] = data[i][j];
        }
    }
    return g;
}

Grid Grid::rotate_180_clockwise() const
{
    ///supports square for now
    assert(r == c);
    Grid g(data);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            g.data[r - i - 1][c - j - 1] = data[i][j];
        }
    }
    return g;
}


Grid Grid::rotate_270_clockwise() const
{
    ///supports square for now
    assert(r == c);
    Grid g(data);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            g.data[r - j - 1][i] = data[i][j];
        }
    }
    return g;
}

Grid Grid::mirror_horizontal() const
{
    ///supports square for now
    assert(r == c);
    Grid g(data);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            g.data[i][c - j - 1] = data[i][j];
        }
    }
    return g;
}

Coords Grid::connected_component(int x, int y) const
{ 
    char ch = data[x][y];
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
            if (nx < r && ny < c && nx >= 0 && ny >= 0 && visited[nx][ny] == 0 && data[nx][ny] == ch) {
                visited[nx][ny] = 1;
                q.push(std::make_pair(nx, ny));
                res.push_back(std::make_pair(nx, ny));
            }
        }
    }
    return res;
}

void Grid::fill_connected_component(int x, int y, char with)
{
    auto coords = connected_component(x, y);
    fill(coords, with);
}
    
void Grid::fill(Coords c, char with)
{
    for (const auto& p: c) {
        data[p.first][p.second] = with;
    }
}


std::ostream& operator << (std::ostream& o, const Grid& g)
{
    for (int i = 0; i < g.r; ++i) {
        for (int j = 0; j < g.c; ++j) {
            o << g.data[i][j];
        }
        o << std::endl;
    }
    return o;
}

}
}
