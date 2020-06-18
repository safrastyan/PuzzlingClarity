std::string back(int x)
{
    std::string res;
    while (x != 0) {
        res.push_back((x % 2) + '0');
        x /= 2;
    }
    return res;
}

int forth(std::string s)
{
    int res = 0;
    std::reverse(s.begin(), s.end());
    for (int i = s.size() - 1; i >= 0; --i) {
        res += (s[i] - '0') << i; 
    }
    return res;
}

int mirrorBits(int a) 
{
    auto bin_str = back(a);
    return forth(bin_str);
}
