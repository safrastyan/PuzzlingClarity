std::vector<int> digits(int x)
{
    std::vector<int> d;
    while (x != 0) {
        d.push_back(x % 10);
        x /= 10;
    }
    return d;
}

int num(std::vector<int>& digs)
{
    int ten = 1;
    int res = 0;
    for (int i = 0; i < digs.size(); ++i) {
        res += digs[i] * ten;
        ten *= 10;
    }
    return res;
}

void pad(std::vector<int>& a, std::vector<int>& b)
{
    for (int i = 0; i < std::abs(static_cast<int>(a.size()) - static_cast<int>(b.size())); ++i) {
        if (a.size() < b.size()) {
            a.push_back(0);
        } else {
            b.push_back(0);
        }
    }
}

int additionWithoutCarrying(int param1, int param2) 
{
    if (param1 == 0 || param2 == 0) {
        return param1 + param2;
    }
    auto a = digits(param1);
    auto b = digits(param2);
    pad(a, b);
    for (int i = 0; i < a.size(); ++i) {
        b[i] += a[i];
        b[i] %= 10;
    }
    return num(b);
}
