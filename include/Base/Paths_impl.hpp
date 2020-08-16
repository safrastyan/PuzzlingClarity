#pragma once

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

inline std::string tests_path()
{
    return resources_path() + "/tests";

}

inline std::string algo_tests_path()
{
    return tests_path() + "/algo";
}

inline std::string io_tests_path()
{
    return tests_path() + "/io";
}

inline std::string linx_standard_dictionary_path() 
{
    return "/usr/share/dict/american-english";
}

}
}
}