#include "Generators/GraphGenerators.hpp"

#include <iostream>

using namespace pc;
int main()
{
    auto g = Generators::graph(20, 40);
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            std::cout << i << " " << g[i][j] << std::endl;
        }
    }
    return 0;
}