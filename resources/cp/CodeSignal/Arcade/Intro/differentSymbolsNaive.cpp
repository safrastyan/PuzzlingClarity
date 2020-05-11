int differentSymbolsNaive(std::string s) 
{
    std::sort(s.begin(), s.end());
    return std::unique(s.begin(), s.end()) - s.begin();
}
