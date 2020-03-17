#pragma once

#include <vector>
#include <ostream>

namespace pc {
namespace algo {

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
    void fill_connected_component(int x, int y, char with);
    
    /// just fill the given cooridnates with the char with
    void fill(Coords c, char with);


    std::vector<std::vector<char>> data;
    int r;
    int c;
};

bool operator == (const Grid& g1, const Grid& g2);

std::ostream& operator << (std::ostream& o, const Grid& g);

}
}
