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

/// calculate the edit distance. Minimum distance to fund 
int edit_distance(const std::string& word1, const std::string& word2);


/// calculate the z function for the string
std::vector<int> z_function(const std::string& s);   /// TODO

/// Check if the given string matches a patterns which contains '.' (wildcard symbol) and '*' symbol
bool pattern_match(const std::string& s, const std::string& p);

}
}
