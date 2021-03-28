#pragma once

#include <vector>

namespace pc {
namespace Generators {

/** 
 * @brief Generates and returns a non-weighted graph
 * @param nodes the number of nodes. Starting node will always be 1
 * @param edges the number of edges
 * @param directed 

 **/

std::vector<std::vector<int>> graph(int nodes, int edges, bool directed=false);


}
}
