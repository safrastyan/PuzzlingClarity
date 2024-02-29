#pragma once

#include <vector>
#include <ostream>

namespace pc {
namespace algo {

/// the basic representation of graph, list of indices for each row indicating connected
using Grid=std::vector<std::vector<char>>;
/// All cooordinates are always represented as ROW FIRST COL SECOND
using Coords=std::vector<std::pair<int, int>>;


/// Those are basic transformation functions
Grid rotate_90_clockwise(const Grid&);
Grid rotate_180_clockwise(const Grid&);
Grid rotate_270_clockwise(const Grid&);
Grid mirror_horizontal(const Grid&);


/// return the connected component connected to position (x, y)
Coords connected_component(const Grid& , int x, int y);

/// fill connected component with the given coords with the character 'with'
void fill_connected_component(Grid& g, int x, int y, char with);

bool operator == (const Grid& g1, const Grid& g2);

std::ostream& operator << (std::ostream& o, const Grid& g);


/// @brief This function will fill the given grid's connected component on the starting coordinate with the new element
/// @tparam T 
/// @param grid 2D vector of elements
/// @param row row of the starting point
/// @param col column of the starting point
/// @param elem new element to fill with
/// @param diagonal boolean parameter. If false, the connected component will be taken account only on 4 directions. If true, 8

/// @return the new grid
template<typename T> 
std::vector<std::vector<T>> fill_connected_component_t(const std::vector<std::vector<T>>& grid, int row, int col, const T& elem, bool diagonal = false);


/// TODO generic flood fill function

}
}

#include "algo/Grids_impl.hpp"
