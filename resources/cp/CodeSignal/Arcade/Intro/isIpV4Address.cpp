std::vector<int> get_numbers(const std::string& s)
{
    std::stringstream stream(s);
    std::string cur;
    std::vector<int> res;
    while (std::getline(stream, cur, '.')) {
        if (cur.size() > 1 && cur[0] == '0') {
            return std::vector<int>();
        }
        if (cur.size() > 3) {
            return std::vector<int>();
        }
        
        res.push_back(std::stoi(cur));
    }

    return res;
}

bool isIPv4Address(std::string inputString) 
{
    for (auto c: inputString) {
        if ( (c < '0' || c > '9') && c != '.') {
            return false;
        }
    }
    if (inputString[0] == '.' || inputString.back() == '.') {
        return false;
    }

    for (int i = 0; i < inputString.size() - 1; ++i) {
        if (inputString[i] == '.' && inputString[i + 1] == '.') {
            return false;
        }
    }

    auto numbers = get_numbers(inputString);
    if (numbers.size() != 4) {
        return false;
    }
    for (auto n: numbers) {
        if (n > 255) {
            return false;
        }
    }
    return true;
}
