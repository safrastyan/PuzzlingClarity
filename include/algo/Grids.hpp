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

}
}
