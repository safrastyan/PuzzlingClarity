std::string lineEncoding(std::string s) 
{
    std::string res;
    while (s.size() != 0) {
        int i = 0;
        for ( ; i < s.size() && s[i] == s[i + 1]; ++i);

        if (i != 0) {
            res += std::to_string(i + 1);
        }
        res.push_back(s[0]);
        s.erase(0, i + 1);
    }
    return res;

}
