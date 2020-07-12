std::string integerToStringOfFixedWidth(int number, int width) 
{
    std::string res = std::to_string(number);
    if (width > res.size()) {
        return std::string(width - res.size(), '0') + res;
    }    
    res.erase(0, res.size() - width);
    return res;
}
