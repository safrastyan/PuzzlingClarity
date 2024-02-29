#pragma once

#include <vector>

namespace pc {
namespace algo {

/// standard representation sparse matrix style. For each node I the I-th row contains a list of id-s of the nodes to which I is connected
using Graph=std::vector<std::vector<int>>;


/// Used for graphs with weights. Every I-th row contains a list of pairs, first 
template<typename T>
using Graph_t=std::vector<std::vector<std::pair<int, T>>>;

using Graph_w=Graph_t<int>;


/// Calculate the shortest path length in a graph from src to dst node. -1 if no path exists
int shortest_path_length(const Graph& g, int src, int dst);


/// Perform prim's algorithm to calculate the minimum spanning tree
int prim_minimum_spanning_tree(const std::vector<std::vector<std::pair<int, int>>>&);


/// @brief Calculates the shortest distance in a weighted graph from node src to all other nodes. Dijkstr'a aslgorithm. All weights must be non negative
/// @param a Input graph with adjacency list format
/// @param src source node
/// @return vector of integers each representing the distance from node src. All unreachable nodes will have the value of std::numeric_limits<int>::max()
std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& a, int src);


/// @brief Calculates the shrotest path between all pairs of vertices with the Floyd Warshall algorithm
/// @param a input graph
/// @return matrix, where each element [i, j] is the shortest path between nodes i and j
std::vector<std::vector<int>> floyd_warshall(const std::vector<std::vector<std::pair<int, int>>>& a);
}
}
