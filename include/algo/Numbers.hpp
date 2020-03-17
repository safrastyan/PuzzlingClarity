#pragma once

#include <string>
#include <vector>

namespace pc {
namespace algo {

/// inpout always base 10
std::string to_base(int n, int b);

/// returns the digits of the number as a vector, in reversed order
std::vector<char> digits(int n);

/// check primeness
bool is_prime(int n);

///length fo the number
int len(int n);

///returns the numbe reverse
int reverse(int n);

///concat
int concat(int x, int y);

/// returns a list of prime numbers in the given range, that are palindromes
std::vector<int> prime_palindromes(int a, int b);

/// greatest common divisor
int gcd(int a, int b);

/// returns a string which is a full binary of this number padded to the given length REVERSED, you need to reverse to use as a normal number
std::string full_binary(int number, int length);

/// convert to roman
std::string to_roman(int n);

}
}
