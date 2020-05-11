std::string longestDigitsPrefix(std::string inputString) 
{
    std::string res;
    for (int i = 0; i < inputString.size(); ++i) {
        if (std::isdigit(inputString[i])) {
            res.push_back(inputString[i]);
            continue;
        }
        break;
    }
    return res;
}
