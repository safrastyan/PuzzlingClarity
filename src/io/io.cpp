#include "io/io.hpp"

namespace pc {
namespace io {

Options::Options(): add_new_line(true)
{}

std::vector<std::vector<int>> read_graph(std::istream& in, bool directed)
{
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        in >> x >> y;
        g[x].push_back(y);
        if (!directed) {
            g[y].push_back(x);
        }
    }
    return g;
}


std::vector<std::vector<std::pair<int, int>>> read_graph_w(std::istream& in, bool directed)
{
    int n, m;
    in >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y, p;
        in >> x >> y >> p;
        g[x].push_back(std::make_pair(y, p));
        if (!directed) {
            g[y].push_back(std::make_pair(x, p));
        }
    }
    return g;
}

std::vector<std::vector<int>> read_tree(std::istream& in, bool directed)
{
    int n;
    in >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        in >> x >> y;
        g[x].push_back(y);
        if (!directed) {
            g[y].push_back(x);
        }
    }
    return g;
}


std::vector<std::vector<std::pair<int, int>>> read_tree_w(std::istream& in, bool directed)
{
    int n, m;
    in >> n;
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, p;
        in >> x >> y >> p;
        g[x].push_back(std::make_pair(y, p));
        if (!directed) {
            g[y].push_back(std::make_pair(x, p));
        }
    }
    return g;
}



std::vector<std::string> read_dictionary(std::istream& in)
{
    std::vector<std::string> res;
    std::string cur;
    while (in >> cur) {
        res.push_back(cur);
    }
    return res;
}

}
}
