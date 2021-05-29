#include "algo/BigInt.hpp"

namespace pc {
namespace algo {

BigInt::BigInt(const std::string& num): m_negative(false) 
{
    for (int i = num.size()-1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            m_num.push_back(num[i] - '0'); 
        }
        else if (num[i] == '-' && i == 0) {
            m_negative = true;
        }
        else {
            throw "kl";
        }
    }
}

BigInt::BigInt(long long num){}

BigInt::BigInt(const BigInt& other){}

BigInt& BigInt::operator=(const BigInt& other){}

BigInt BigInt::operator-() const{}

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
