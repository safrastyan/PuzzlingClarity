int dist(const std::string& s1, const std::string& s2)
{
    int c = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++c;
        }
    }
    return c;
}

bool check(const std::vector<std::string>& a)
{
    for (int i = 0; i < a.size() - 1; ++i) {
        if (dist(a[i], a[i + 1]) != 1) {
            return false;
        }
    }
    return true;
}

bool stringsRearrangement(std::vector<std::string> inputArray) 
{
    std::sort(inputArray.begin(), inputArray.end());
    if (check(inputArray)) {
        return true;
    }
    while (std::next_permutation(inputArray.begin(), inputArray.end())) {
        if (check(inputArray)) {
            return true;
        }
    }
    return false;
}   
