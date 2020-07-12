int stringsConstruction(std::string a, std::string b) 
{
    int res = b.size();
    for (int i = 0; i < 26; ++i) {
        int charas = std::count(a.begin(), a.end(), 'a' + i);
        int charbs = std::count(b.begin(), b.end(), 'a' + i);
        if (charas == 0) {
            continue;;
        }
        res = std::min(res, charbs / charas);
    }
    return res;
}
///abc
///abcba
/// min(for each charater from b / for each character from a (correspondigly))
