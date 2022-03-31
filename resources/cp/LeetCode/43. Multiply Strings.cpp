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


class Solution {
public:
    string multiply(string num1, string num2) 
    {
        BigInt res = BigInt(num1) * BigInt(num2);
        return res.to_string();
    }
};

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
    if (num == 0) {
        m_num.push_back(0);
    }
    while (num > 0)
    {
        m_num.push_back(num % 10);
        num /= 10;
    }
}

BigInt::BigInt(const BigInt& other) : m_negative(other.m_negative), m_num(other.m_num)
{
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

BigInt BigInt::operator*(const BigInt& other) const
{
    return mul(*this, other);
}

BigInt BigInt::operator/(const BigInt& other) const
{
    return div(*this, other);
}

BigInt BigInt::operator%(const BigInt& other) const
{
    BigInt res = *this / other;
    res = *this - res * other;
    res.m_negative = this->m_negative;
    return res;
}

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
    return *this;
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
    return *this;
}

BigInt& BigInt::operator*=(const BigInt& other)
{
    BigInt res = mul(*this, other);
    this->m_negative = res.m_negative;
    this->m_num = res.m_num;
    return *this;
}

BigInt& BigInt::operator/=(const BigInt& other)
{
    BigInt res = div(*this, other);
    this->m_negative = res.m_negative;
    this->m_num = res.m_num;
    return *this;
}

BigInt& BigInt::operator%=(const BigInt& other)
{
    BigInt res = *this % other;
    this->m_negative = res.m_negative;
    this->m_num = res.m_num;
    return *this;
}

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
    for (int i = a.m_num.size() - 1; i > 0; --i) {
        if (a.m_num[i] != 0) {
            break;
        }
        a.m_num.pop_back();
    }
    a.m_negative = false;
}

BigInt BigInt::mul(const BigInt& a, const BigInt& b)
{
    BigInt res(0);
    if (a == 0 || b == 0) {
        return res;
    }
    for (int i = 0; i < b.m_num.size(); ++i) {
        BigInt tmp(0);
        for (int j = 0; j < i; ++j) {
            tmp.m_num.push_back(0);
        }
        for (int j = 0; j < a.m_num.size(); ++j) {
            short num = b.m_num[i] * a.m_num[j];
            short num1 = num % 10;
            short num2 = num / 10;
            int ind = j  + i;
            if (tmp.m_num.size() <= ind) {
                tmp.m_num.push_back(0);
            }
            short sum = tmp.m_num[ind] + num1;
            num1 = sum % 10;
            num2 += sum / 10;
            tmp.m_num[ind] = num1;
            if (num2 > 0) {
                tmp.m_num.push_back(num2);
            }
        }
        res += tmp;
    }
    res.m_negative = a.m_negative != b.m_negative;
    return res;
}

BigInt BigInt::div(const BigInt& a, const BigInt& b)
{
    if (b == 0) {
        throw "Zero division";
    }
    BigInt num1 = a.abs();
    BigInt num2 = b.abs();
    if (num1 < num2) {
        return 0;
    }
    BigInt res("");
    bool last_zero = false;
    int last_len = 0;
    while (num1.m_num.size() > 0) {
        BigInt tmp("");
        int digit = 0;
        if (num1.m_num[num1.m_num.size() - 1] == 0) {
            res.m_num.push_back(0);
            num1.m_num.pop_back();
            continue;
        }
        for (int i = num1.m_num.size() - 1; i >= 0; --i) {
            tmp.m_num = std::vector<short>(num1.m_num.begin() + i, num1.m_num.end());
            if (tmp >= num2) {
                break;
            }
        }
        if (res.m_num.size() > 0) {
            for (int i = 0; i < (int)tmp.m_num.size() - last_len - 1; ++i) {
                res.m_num.push_back(0);
            }
        }
        if (tmp < num2) {
            if ((int)tmp.m_num.size() - last_len > 0) {
                res.m_num.push_back(0);
            }
            break;
        }
        for (int i = 1; i < 10; ++i) {
            if (num2 * i > tmp) {
                break;
            }
            digit = i;
        }
        int sz = tmp.m_num.size();
        res.m_num.push_back(digit);
        tmp -= num2 * digit;
        last_zero = false;
        last_len = tmp.m_num.size();
        if (tmp == 0) {
            tmp.m_num.pop_back();
            last_zero = true;
            last_len = 0;
        }
        for (int i = 0; i < sz; ++i) {
            num1.m_num.pop_back();
        }
        for (int i = 0; i < tmp.m_num.size(); ++i) {
            num1.m_num.push_back(tmp.m_num[i]);
        }
    }
    std::reverse(res.m_num.begin(), res.m_num.end());
    res.m_negative = a.m_negative != b.m_negative;
    return res;
}