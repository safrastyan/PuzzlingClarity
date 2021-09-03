#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace pc {
namespace algo {

class BigInt 
{
public:
    BigInt(const std::string& num);
    BigInt(long long num);

    BigInt(const BigInt& other);

    BigInt& operator=(const BigInt& other);

    BigInt operator-() const;

    BigInt& operator++();
    BigInt& operator--();
    BigInt operator++(int);
    BigInt operator--(int);
    
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;

    BigInt& operator+=(const BigInt& other);
    BigInt& operator-=(const BigInt& other);
    BigInt& operator*=(const BigInt& other);
    BigInt& operator/=(const BigInt& other);
    BigInt& operator%=(const BigInt& other);

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    BigInt abs() const;

    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);

private:
    std::vector<short> m_num;
    bool m_negative;

    // Add the absolute values of two bigints and assign to the first one 
    static void add_abs(BigInt& a, const BigInt& b);
    // Subtract the absolute value of b from a and assign to a
    static void sub_abs(BigInt& a, const BigInt& b);
    // Subtract the absolute value of b from a and assign to a, works for a >= b
    static void sub_abs_impl(BigInt& a, const BigInt& b);

    static BigInt mul(const BigInt& a, const BigInt& b);

    static BigInt div(const BigInt& a, const BigInt& b);
};

}
}
