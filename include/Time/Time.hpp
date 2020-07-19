#pragma once

#include <string>
#include <iostream>

namespace pc {
namespace Time {

/**
 * Timing functions. 
 */

/**
 * Push the current timestamp to the stack of timestamps
 */
void push();

/** Pop the current timestamp. 
 * @param str . Will print the string and the time
 * @param stream . The stream to which to write to. Default std::cout
 */
double pop(const std::string& str, std::ostream& out = std::cout);


}
}