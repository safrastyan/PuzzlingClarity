#pragma once

/**
 * This file is for generators for test cases 
 * So the test case generator is kind of like the opposite of running of the test cases. Because the generator should trust the functon it is using for generating the test cases or else the whole thing will turn into one big bullshit
 **/

#include <string>

namespace pc {
namespace Generators {
namespace TestCaseGenerators {

//// generate test cases for sorting
void generate_sortings(const std::string& path, int count);

}
}
}