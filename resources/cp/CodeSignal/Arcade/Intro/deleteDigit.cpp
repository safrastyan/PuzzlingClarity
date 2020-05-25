int deleteDigit(int n) 
{
    std::string s = std::to_string(n);
    int res = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        std::string n = s;
        n.erase(i, 1);
        res = std::max(res, std::stoi(n));
    }

    return res;    
}
