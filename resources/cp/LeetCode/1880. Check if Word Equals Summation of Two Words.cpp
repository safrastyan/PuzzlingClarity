class Solution {
public:
    long long num(const std::string& s)
    {
        std::string res;
        for (auto c: s) {
            res += std::to_string(c - 'a');
        }
        return std::stoll(res);
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return num(firstWord) + num(secondWord) == num(targetWord);
    }
};