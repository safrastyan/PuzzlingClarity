int commonCharacterCount(std::string s1, std::string s2) 
{
    int res = 0;
    for (auto c: s1) {
        int found = s2.find(c);
        if (s2.find(c) != std::string::npos) {
            ++res;
            s2.erase(found, 1);
        }
    }
    return res;
}
