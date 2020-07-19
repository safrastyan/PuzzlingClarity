#pragma once

#include <iostream>
#include <fstream>

namespace pc {
namespace io {

/**
 *  Options for configurinig projectwise input output mechanism
 */
struct Options
{
    /**
     * @param add_new_line whether to add a new line at the end of output or not. default true
     */    
    Options();
    bool add_new_line;

};

/**
 * Generic funnction for printing. Will be specializations for different types
 * @param obj object to print. For unspecialized cases the obejct's << operator will be used
 * @param str Supporting text. On the default case will be printed before the object
 * @param out the output stream to which to write to. Default value - std::cout
 * @param options Various outputting options. Immplicitly will be costructed by one string which will be used. 
 */
template<typename T>
void write(const T& obj, const std::string& str = std::string(), std::ostream& out = std::cout, Options op = Options())
{   
    if (!str.empty()) {
        out << str << std::endl;
    }
    out << obj;
    if (op.add_new_line) {
        out << std::endl;
    }
}


}
}

#include "io_impl.hpp"