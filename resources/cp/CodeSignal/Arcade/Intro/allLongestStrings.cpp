std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) 
{
    int size = 0;
    for (auto& s: inputArray) {
        size = std::max(static_cast<size_t>(size), s.size());
    }

    std::vector<std::string> res;
    for (auto& s: inputArray) {
        if (s.size() == size) {
            res.push_back(s);
        }
    }

    return res;
}
