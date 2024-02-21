class Solution {
public:
    bool is_vowel(char c)
    {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        std::string vow;
        for (auto c: s) {
            if (!is_vowel(c)) {
                 continue;
            }
            vow.push_back(c);  
        }
        std::sort(vow.begin(), vow.end());
        std::string res;
        int point = 0;
        for (auto c: s) {
            if (is_vowel(c)) {
                res.push_back(vow[point]);
                ++point;
                continue;
            }
            res.push_back(c);
        }
        
        return res;
    }
};