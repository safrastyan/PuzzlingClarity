/*
ID: safrast1
TASK: transform
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>



///A rectangular grid
class Grid
{
public:
    Grid(int r, int c);
    Grid(const std::vector<std::vector<char>>&);

    void rotate_90_clockwise();
    void rotate_180_clockwise();
    void rotate_270_clockwise();
    void mirror_horizontal();


    std::vector<std::vector<char>> data;
    int r;
    int c;
};

bool operator == (const Grid& g1, const Grid& g2);



Grid::Grid(int r_, int c_): data(r_, std::vector<char>(c_))
                          , r(r_)
                          , c(c_)
{}

Grid::Grid(const std::vector<std::vector<char>>& d): data(d)
                                                   , r(d.size())
                                                   , c(d[0].size())
{}                                                         


void Grid::rotate_90_clockwise()
{
    ///supports square for now
    assert(r == c);
    std::vector<std::vector<char>> t = data;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t[j][c - i - 1] = data[i][j];
        }
    }
    data = t;
}

void Grid::rotate_180_clockwise()
{
    ///supports square for now
    assert(r == c);
    std::vector<std::vector<char>> t = data;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t[r - i - 1][c - j - 1] = data[i][j];
        }
    }
    data = t;
}


void Grid::rotate_270_clockwise()
{
    ///supports square for now
    assert(r == c);
    std::vector<std::vector<char>> t = data;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t[r - j - 1][i] = data[i][j];
        }
    }
    data = t;
}

void Grid::mirror_horizontal()
{
    ///supports square for now
    assert(r == c);
    std::vector<std::vector<char>> t = data;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t[i][c - j - 1] = data[i][j];
        }
    }
    data = t;
}

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


int solve(const Grid& g1, const Grid& g2)
{
    auto t1 = g1;
    t1.rotate_90_clockwise();

    if (t1 == g2) {
        return 1;
    }

    t1 = g1;
    t1.rotate_180_clockwise();
    if (t1 == g2) {
        return 2;
    }

    t1 = g1;
    t1.rotate_270_clockwise();
    if (t1 == g2) {
        return 3;
    }

    t1 = g1;
    t1.mirror_horizontal();
    if (t1 == g2) {
        return 4;
    }

    auto c1 = t1;
    auto c2 = t1;
    auto c3 = t1;
    c1.rotate_90_clockwise();
    c2.rotate_180_clockwise();
    c3.rotate_270_clockwise();

    if (c1 == g2 || c2 == g2 || c3 == g2) {
        return 5;
    }

    if (g1 == g2) {
        return 6;
    }
    return 7;

}

int main() 
{
    std::ifstream fin ("transform.in");
    std::ofstream fout ("transform.out");

    int n;
    fin >> n;
    std::vector<std::vector<char>> d1(n, std::vector<char>(n));
    auto d2 = d1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> d1[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> d2[i][j];
        }
    }

    const Grid g1(d1);
    const Grid g2(d2);

    fout << solve(g1, g2) << std::endl;
    return 0;
}