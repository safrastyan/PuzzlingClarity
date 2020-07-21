#include "io/io.hpp"

namespace pc {
namespace io {

Options::Options(): add_new_line(true)
{}

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
