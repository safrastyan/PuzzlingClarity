#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace pc {
namespace algo {

bool is_palindrome(const std::string&);

int hamming_distance(const std::string&, const std::string&);

bool is_correct_bracket_expr(const std::string&);

bool is_vowel(char);   

/// Splits the string into words by spaces 
std::vector<std::string> split(const std::string&);


}
}
