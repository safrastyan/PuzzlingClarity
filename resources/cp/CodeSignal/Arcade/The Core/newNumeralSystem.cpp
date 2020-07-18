std::vector<std::string> newNumeralSystem(char number) 
{
    std::vector<std::string> res;
    for (int i = 0; i < 26; ++i) {
        for (int j = i; j < 26; ++j) {
            if (i + j == (number - 'A')) {
                std::string temp;
                temp += 'A' + i;
                temp += " + ";
                temp += 'A' + j;
                res.push_back(temp);
            }
        }
    }
    return res;
}
