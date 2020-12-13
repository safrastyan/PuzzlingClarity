#pragma once

#include <string>

namespace pc {
namespace Generators {

std::string random_string(int n);
std::string random_string_alnum(int n);

// high quality random string
std::string random_string_hq(const int len);

}
}
