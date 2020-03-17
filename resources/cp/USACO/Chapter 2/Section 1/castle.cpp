/*
ID: safrast1
TASK: castle
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <array>
#include <cassert>

/// the basic representation of graph, list of indices for each row indicating connected
using Graph_t=std::vector<std::vector<int>>;
/// conrdinates
using Coords=std::vector<std::pair<int, int>>;

/// all the cooridnates are always row-first
class Grid
{
public:
    Grid(int r, int c);
    Grid(int r, int c, char fill_with);
    Grid(const std::vector<std::vector<char>>&);

    Grid rotate_90_clockwise() const;
    Grid rotate_180_clockwise() const;
    Grid rotate_270_clockwise() const;
    Grid mirror_horizontal() const;

    /// get the cooridnates of the connected component starting from the given coordinate
    Coords connected_component(int x, int y) const;

    /// fill connected component with the given coords with the character 'with'
    int fill_connected_component(int x, int y, char with);
    
    /// just fill the given cooridnates with the char with
    void fill(Coords c, char with);


    std::vector<std::vector<char>> data;
    int r;
    int c;
};

bool operator == (const Grid& g1, const Grid& g2);

/// mechanical operations on the Grid


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
    static std::vector<std::vector<int>> visited(r, std::vector<int>(c, 0));
    for (int i  = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            visited[i][j] = 0;
        }
    }
    
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> res;
    res.reserve(1000);
    
    q.push(std::make_pair(x, y));
    res.push_back(std::make_pair(x, y));
    visited[x][y] = 1;
    static int px[] = {-1, 1, 0, 0};
    static int py[] = {0, 0, -1, 1};
   
    return res;
}

int Grid::fill_connected_component(int x, int y, char with)
{
    int res = 1;
    char ch = data[x][y];
    
    std::queue<std::pair<int, int>> q;
    
    q.push(std::make_pair(x, y));
    data[x][y] = with;
    static int px[] = {-1, 1, 0, 0};
    static int py[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + px[i];
            int ny = cy + py[i];
            if (nx < r && ny < c && nx >= 0 && ny >= 0 && data[nx][ny] == ch) {
                int rx = cx + px[i] * 3;
                int ry = cy + py[i] * 3;
                if (data[rx][ry] == ch) {
                    q.push(std::make_pair(rx, ry));
                    ++res;
                    data[rx][ry] = with;
                }
            }
        }
    }
    return res;

}
    
void Grid::fill(Coords c, char with)
{
    for (const auto& p: c) {
        data[p.first][p.second] = with;
    }
}

std::string full_binary(int num, int length)
{
    std::string s(length, '0');
    int i = 0;
    while (num != 0) {
        s[i] = '0' + num % 2;
        num /= 2;
        ++i;
    }
    return s;
}


std::string get_wall_bitmask(int x)
{
    static constexpr std::array<int, 4> nums = {1, 2, 4, 8};
    for (int i = 0; i <= 15; ++i) {
        auto bin = full_binary(i, 4);
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
            if (bin[k] == '1') {
                sum += nums[k];
            }
        }
        if (sum == x) {
            return bin;
        }
    }
}

void draw_walls_with_mask(Grid& g, int x, int y, const std::string& mask)
{
    if (mask[0] == '1') {
        g.data[x + 1][y - 1] = g.data[x][y - 1] = g.data[x - 1][y - 1] = '#';
    }
    if (mask[1] == '1') {
        g.data[x - 1][y - 1] = g.data[x - 1][y] = g.data[x - 1][y + 1] = '#';
    }
    if (mask[2] == '1') {
        g.data[x - 1][y + 1] = g.data[x][y + 1] = g.data[x + 1][y + 1] = '#';
    }
    if (mask[3] == '1') {
        g.data[x + 1][y + 1] = g.data[x + 1][y] = g.data[x + 1][y - 1] = '#';
    }
}

//first size, second count
std::pair<int, int> rooms_and_largest(const Grid& g)
{
    int rooms = 0;
    int largest = 1;
    Grid g2 = g;
    for (int i = 0; i < g.r / 3; ++i) {
        for (int j = 0; j < g.c / 3; ++j) {
            if (g2.data[i * 3 + 1][j * 3 + 1] == '.') {
                int size = g2.fill_connected_component(i * 3 + 1, j * 3 + 1, '#');
                ++rooms;
                largest = std::max(largest, size);
            }
        }
    }
    return std::make_pair(largest, rooms);
}


/// size coordinates and the pole
std::tuple<int, int, int, char> solve(const Grid& g)
{
    int size_so_far = 0;
    char dir = 'a';
    int x = 0;
    int y = 0;
    for (int j = 0; j < g.c / 3; ++j) {
        for (int i = g.r / 3 - 1; i >= 0; --i) {
            
            ///try N
            auto g1 = g;
            if (i != 0 && g1.data[i * 3][j * 3 + 1] == '#') {
                g1.data[i * 3][j * 3 + 1] = g1.data[i * 3 - 1][j * 3 + 1] = '.';
                
                auto new_d =  g1.fill_connected_component(i * 3 + 1, j * 3 + 1, '#');
                if (new_d > size_so_far) {
                    dir = 'N';
                    x = i + 1;
                    y = j + 1;
                    size_so_far = new_d;
                }
            }

            g1 = g;

            ///try E
            if (j != g.c / 3 - 1 && g1.data[i * 3 + 1][j * 3 + 2] == '#') {
                g1.data[i * 3 + 1][j * 3 + 2] = g1.data[i * 3 + 1][j * 3 + 3] = '.';
                auto new_d =  g1.fill_connected_component(i * 3 + 1, j * 3 + 1 , '#');
                if (new_d > size_so_far) {
                    dir = 'E';
                    x = i + 1;
                    y = j + 1;
                    size_so_far = new_d;
                }
                
            }

        }
    }
   
    return std::make_tuple(size_so_far, x, y, dir);
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


int main() 
{
    std::ifstream fin ("castle.in");
    std::ofstream fout ("castle.out");
    
    int n, m;
    fin >> m >> n;
    Grid g(3 * n, 3 * m, '.');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            fin >> a;
            auto mask = get_wall_bitmask(a);
            draw_walls_with_mask(g, i * 3 + 1, j * 3 + 1, mask);            
        }
    }
    auto  r1 = rooms_and_largest(g);
    auto ans = solve(g);
    fout << r1.second << std::endl << r1.first << std::endl << std::get<0>(ans) << std::endl << std::get<1>(ans) << " " << std::get<2>(ans) << " " << std::get<3>(ans) << std::endl;
    return 0;
}