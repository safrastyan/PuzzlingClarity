#pragma once

#include <string>

namespace pc {
namespace base {
namespace paths {

inline std::string pc_path()
{
    return getenv("PCPATH");
}

inline std::string resources_path()
{
    return pc_path() + "/resources";
}

inline std::string linx_standard_dictionary_path() 
{
    return "/usr/share/dict/american-english";
}

}
}
}