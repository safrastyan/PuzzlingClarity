#pragma once

#include <string>

namespace pc {
namespace base {
namespace paths {


std::string pc_path();
std::string resources_path();
std::string tests_path();
std::string algo_tests_path();
std::string io_tests_path();
std::string linx_standard_dictionary_path();
std::string tasks_test_path();


}
}
}

#include "Paths_impl.hpp"