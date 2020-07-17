#pragma once

#include <vector>
#include <string>

namespace pc {
namespace Utils {

/// generic printing function
template<typename T>
void print(const T& obj, const std::string& meta_text) ;

}
}

#include "Utils/Printer_impl.hpp"