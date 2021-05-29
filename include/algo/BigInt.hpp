#pragma once

#include <string>
#include <vector>

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
    bool operator<(const BigInt& other) const;

private:
    std::vector<short> m_num;
    bool m_negative;
};

}
}
