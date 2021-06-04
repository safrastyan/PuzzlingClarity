#include "algo/BigInt.hpp"

namespace pc {
namespace algo {

BigInt::BigInt(const std::string& num): m_negative(false) 
{
    for (int i = num.size()-1; i >= 0; --i) {
        if (std::isdigit(num[i])) {
            m_num.push_back(num[i] - '0');
        }
        else if (num[i] == '-' && i == 0) {
            m_negative = true;
        }
    }
}

BigInt::BigInt(long long num): m_negative(false)
{
    if (num < 0) {
        m_negative = true;
        num *= -1;
    }
    while (num > 0)
    {
        m_num.push_back(num % 10);
        num /= 10;
    }
}

BigInt::BigInt(const BigInt& other)
{
    m_negative = other.m_negative;
    m_num = other.m_num;
}

BigInt& BigInt::operator=(const BigInt& other)
{
    m_negative = other.m_negative;
    m_num = other.m_num;
    return *this;
}

BigInt BigInt::operator-() const
{
    BigInt bigint = *this;
    bigint.m_negative = !m_negative;
    return bigint;
}

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

bool BigInt::operator==(const BigInt& other) const
{
    if (m_num.size() == 1 && other.m_num.size() == 1 && 
        m_num[0] == 0 && other.m_num[0] == 0) {
        return true;
    }
    if (m_negative != other.m_negative) {
        return false;
    }
    if (m_num.size() != other.m_num.size()) {
        return false;
    }
    for (int i = 0; i < m_num.size(); ++i) {
        if (m_num[i] != other.m_num[i]) {
            return false;
        }
    }
    return true;
}

bool BigInt::operator!=(const BigInt& other) const
{
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const
{
    if (*this == other) {
        return false;
    } 
    if (!m_negative && other.m_negative) {
        return false;
    }
    if (m_negative && !other.m_negative) {
        return true;
    }
    bool abs_less = false;
    if (m_num.size() > other.m_num.size()) {
        abs_less = false;
    }
    else if (m_num.size() < other.m_num.size()) {
        abs_less = true;
    }
    else {    
        for (int i = m_num.size() - 1; i >= 0; --i) {
            if (m_num[i] < other.m_num[i]) {
                abs_less = true;
                break;
            }
            if (m_num[i] > other.m_num[i]) {
                break;
            }
        }
    }
    return (m_negative && other.m_negative) ? !abs_less : abs_less;
}

bool BigInt::operator<=(const BigInt& other) const
{
    return *this == other || *this < other;
}

bool BigInt::operator>(const BigInt& other) const
{
    return !(*this <= other);
}

bool BigInt::operator>=(const BigInt& other) const
{
    return *this == other || *this > other;
}

std::string BigInt::to_sting() const
{
    std::string str = "";
    if (m_negative) {
        str += "-";
    }
    for (int i = m_num.size()-1; i >= 0; i--) {
        str += '0' + m_num[i];
    }
    return str;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint)
{
    os << bigint.to_sting();
    return os;
}

}
}
