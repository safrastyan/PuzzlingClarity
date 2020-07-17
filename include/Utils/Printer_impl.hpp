#pragma once

#include "Utils/Printer.hpp"

#include <iostream>

namespace pc {
namespace Utils {

/// for array metatext will be printed before the array
template<>
inline void print(const std::vector<int>& obj, const std::string& meta_text)
{
    if (!meta_text.empty()) {
        std::cout << meta_text << std::endl;
    }
    for (auto x: obj) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

/// for the matrix meta text will be printed before each row with index
template<>
inline void print(const std::vector<std::vector<int>>& obj, const std::string& meta_text)
{
    for (int i = 0; i < obj.size(); ++i) {
        if (meta_text.size() != 0) {    
            std::cout << meta_text << " " << i <<std::endl;
        }
        for (auto y: obj[i]) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
}

}
}
