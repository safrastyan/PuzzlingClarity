class Solution {
public:
    string reverseOnlyLetters(string s) {
        std::string let;
        for (auto c: s) {
            if (std::isalpha(c)) {
                let.push_back(c);
            }
        }
        std::reverse(let.begin(), let.end());
        int pos = 0;
        for (auto& c: s) {
            if (std::isalpha(c)) {
                c = let[pos];
                ++pos;
            }
        }
        return s;
    }
};