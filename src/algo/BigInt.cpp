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

BigInt& BigInt::operator++()
{
    *this += 1;
    return *this;
}

BigInt& BigInt::operator--()
{
    *this -= 1;
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt res = *this;
    *this += 1;
    return res;
}

BigInt BigInt::operator--(int)
{
    BigInt res = *this;
    *this -= 1;
    return res;
}

BigInt BigInt::operator+(const BigInt& other) const
{
    BigInt res = *this;
    res += other;
    return res;
}

BigInt BigInt::operator-(const BigInt& other) const
{
    BigInt res = *this;
    res -= other;
    return res;
}

BigInt BigInt::operator*(const BigInt& other) const{}
BigInt BigInt::operator/(const BigInt& other) const{}
BigInt BigInt::operator%(const BigInt& other) const{}

BigInt& BigInt::operator+=(const BigInt& other)
{
    if (this->m_negative == other.m_negative) {
        BigInt::add_abs(*this, other);
        this->m_negative = other.m_negative;
    }
    else {
        BigInt::sub_abs(*this, other);
        this->m_negative = this->m_negative == other.m_negative;
    }
}

BigInt& BigInt::operator-=(const BigInt& other)
{
    if (this->m_negative == other.m_negative) {
        BigInt::sub_abs(*this, other);
        this->m_negative = this->m_negative != other.m_negative;
    }
    else {
        BigInt::add_abs(*this, other);
        this->m_negative = !other.m_negative;
    }
}

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

BigInt BigInt::abs() const 
{
    BigInt bigint = *this;
    bigint.m_negative = false;
    return bigint;
}

std::string BigInt::to_string() const
{
    std::string str = "";
    if (m_negative) {
        str += "-";
    }
    for (int i = m_num.size() - 1; i >= 0; --i) {
        str += '0' + m_num[i];
    }
    return str;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint)
{
    os << bigint.to_string();
    return os;
}

void BigInt::add_abs(BigInt& a, const BigInt& b) 
{
    std::size_t len = std::max(a.m_num.size(), b.m_num.size());
    a.m_num.resize(len, 0);
    short carry = 0;
    for (int i = 0; i < len; ++i) {
        short res = a.m_num[i] + carry;
        if (i < b.m_num.size()) {
            res += b.m_num[i];
        }
        a.m_num[i] = res % 10;
        carry = res / 10;
    }
    if (carry > 0) {
        a.m_num.push_back(carry);
    }
    a.m_negative = false;
}


void BigInt::sub_abs(BigInt& a, const BigInt& b) 
{
    if (a.abs() >= b.abs()) {
        sub_abs_impl(a, b);
    }
    else {
        BigInt res = b;
        sub_abs_impl(res, a);
        a.m_num = res.m_num;
        a.m_negative = true;
    }
}

void BigInt::sub_abs_impl(BigInt& a, const BigInt& b) 
{
        
    short carry = 0;
    for (int i = 0; i < a.m_num.size(); ++i) {
        short sub = carry;
        carry = 0;
        if (i < b.m_num.size()) {
            sub += b.m_num[i];
        }
        if (a.m_num[i] < sub) {
            a.m_num[i] += 10 - sub;
            carry = 1;
        }
        else {
            a.m_num[i] -= sub;
        }
    }
    for (int i = a.m_num.size()-1; i > 0; --i) {
        if (a.m_num[i] != 0) {
            break;
        }
        a.m_num.pop_back();
    }
    a.m_negative = false;
}

}
}
