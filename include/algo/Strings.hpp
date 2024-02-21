#pragma once

#include <string>

namespace pc {
namespace algo {

bool is_palindrome(const std::string&);

int hamming_distance(const std::string&, const std::string&);

bool is_correct_bracket_expr(const std::string&);

bool is_vowel(char);   /// TODO add a unit test for this

///TODO bring a string splitting function here
}
}
