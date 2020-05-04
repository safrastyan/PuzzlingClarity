std::vector<std::string> addBorder(std::vector<std::string> picture) 
{
    std::vector<std::string> res;
    int m = picture[0].size();
    std::string stars(m + 2, '*');
    res.push_back(stars);
    for (auto& s: picture) {
        res.push_back(std::string(1, '*') + s + "*");
    }
    res.push_back(stars);
    return res;
}
