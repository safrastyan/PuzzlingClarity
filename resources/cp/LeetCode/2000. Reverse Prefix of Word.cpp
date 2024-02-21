class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto f = word.find(ch);
        if (f != std::string::npos) {
            std::reverse(word.begin(), word.begin() + f + 1);
        }
        return word;
    }
};