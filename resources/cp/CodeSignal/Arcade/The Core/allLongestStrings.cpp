std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) 
{
    std::vector<std::string> res;
    size_t len = 0;
    for (const auto& s: inputArray) {
        len = std::max(len, s.size());
    }
    for (const auto& s: inputArray) {
        if (s.size() == len) {
            res.push_back(s);
        }
    }
    return res;
}
