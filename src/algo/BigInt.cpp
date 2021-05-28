#include "algo/BigInt.hpp"

namespace pc {
namespace algo {

BigInt::BigInt(const std::string& num){}
BigInt::BigInt(long long num){}

BigInt::BigInt(const BigInt& other){}

BigInt BigInt::operator=(const BigInt& other){}

BigInt BigInt::operator-(){}

BigInt& BigInt::operator++(){}
BigInt& BigInt::operator--(){}
BigInt BigInt::operator++(int){}
BigInt BigInt::operator--(int){}

BigInt BigInt::operator+(const BigInt& other) const{}
BigInt BigInt::operator-(const BigInt& other) const{}
BigInt BigInt::operator*(const BigInt& other) const{}
BigInt BigInt::operator/(const BigInt& other) const{}
BigInt BigInt::operator%(const BigInt& other) const{}

BigInt& BigInt::operator+=(const BigInt& other){}
BigInt& BigInt::operator-=(const BigInt& other){}
BigInt& BigInt::operator*=(const BigInt& other){}
BigInt& BigInt::operator/=(const BigInt& other){}
BigInt& BigInt::operator%=(const BigInt& other){}

bool BigInt::operator==(const BigInt& other) const{}
bool BigInt::operator<(const BigInt& other) const{}

}
}
