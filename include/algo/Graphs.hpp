#pragma once

#include <vector>

namespace pc {
namespace algo {

/// standard representation sparse matrix style. For each node I the I-th row contains a list of id-s of the nodes to which I is connected
using Graph=std::vector<std::vector<int>>;


/// Used for graphs with weights. Every I-th row contains a list of pairs, first 
template<typename T>
using Graph_t=std::vector<std::vector<std::pair<int, T>>>;


/// Calculate the shortest path length in a graph from src to dst node. -1 if no path exists
int shortest_path(const Graph& g, int src, int dst);




}
}
