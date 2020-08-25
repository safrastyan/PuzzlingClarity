#include "Generators/TextGenerators.hpp"

#include <random>
#include <algorithm>

namespace pc {
namespace Generators {

std::string random_string(int n)
{
    std::string res;
    for (int i = 0; i < n; ++i) {
        res.push_back(static_cast<char>(std::rand() % 256));
    }
    return res;
}

std::string random_string_alnum(int n)
{
    static std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::string res;
    for (int i = 0; i < n; ++i) {
        res.push_back(static_cast<char>(str[std::rand() % str.size()]));
    }
    return res;
}

}
}