std::vector<int> digits(int n)
{
    std::vector<int> res;
    while (n != 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

bool isLucky(int n) 
{
    auto digs = digits(n);
    if (digs.size() % 2 != 0) {
        return false;
    }
    int s1 = 0, s2 = 0;
    for (int i = 0; i < digs.size() / 2; ++i) {
        s1 += digs[i];
        s2 += digs[i + digs.size() / 2];
    }
    return s1 == s2;
}
