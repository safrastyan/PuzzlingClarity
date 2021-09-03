#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace pc {
namespace io {

/**
 *  Options for configurinig projectwise input output mechanism
 */
struct Options
{
    /**
     * @param add_new_line whether to add a new line at the end of output or not. default true
     */    
    Options();
    bool add_new_line;

};

/**
 * Generic funnction for printing. Will be specializations for different types
 * @param obj object to print. For unspecialized cases the obejct's << operator will be used
 * @param str Supporting text. On the default case will be printed before the object
 * @param out the output stream to which to write to. Default value - std::cout
 * @param options Various outputting options. Immplicitly will be costructed by one string which will be used. 
 */
template<typename T>
void write(const T& obj, const std::string& str = std::string(), std::ostream& out = std::cout, Options op = Options())
{   
    if (!str.empty()) {
        out << str << std::endl;
    }
    out << obj;
    if (op.add_new_line) {
        out << std::endl;
    }
}

/**
 * Reading functions, less generic, more to the point
 */


/// Read one thing, number, string, float.
template<typename T>
T read_one(std::istream&);

/// Read an array where the first input comes as a number of the elements, and the test are the elements themselves. 
template<typename T>
std::vector<T> read_array(std::istream&);


/// Read array with unknown number of elements. AKA the whole input and return. 
template<typename T>
std::vector<T> read_array_u(std::istream&);

/// Read an array where the first input comes as a number of elements, after thait pairs of elements, correspndingly wiht type T and U
template<typename T, typename U>
std::vector<std::pair<T, U>> read_array(std::istream&); 

/**
 * @brief Reads the graph with the following format. First 2 numbers, N and M representing the number of nodes
 *                  and the number of edges respectively. Then reads M lines, each with 2 values, source node connected to destination node. 
 * @param directed. If False, the reader will treat it is indirected graph and will make sure to have 2 entries in the adhacency list 
 *                   for each pair [i, j], one entry in the i-th row, another in the j-th row. 
 **/
std::vector<std::vector<int>> read_graph(std::istream&, bool directed = false);

/// Same as above, but also reads weights
std::vector<std::vector<std::pair<int, int>>> read_graph_w(std::istream&, bool directed = false);

/// Same as read graph, but will read n - 1 edges by default, there is no M input.
std::vector<std::vector<int>> read_tree(std::istream&, bool directed = false);

/// Same as above for weighted trees
std::vector<std::vector<std::pair<int, int>>> read_tree_w(std::istream&, bool directed = false);


/// Read the file line by line until the end treating all of them as strings
std::vector<std::string> read_dictionary(std::istream& in);


}
}

#include "io_impl.hpp"