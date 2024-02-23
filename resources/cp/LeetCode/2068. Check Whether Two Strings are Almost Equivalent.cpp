class Solution {
public:

    std::vector<int> bucket_letters(const std::string& s)
    {
        std::vector<int> a(26, 0);
        for (auto c: s) {
            ++a[c - 'a'];
        }
        return a;
    }

    bool checkAlmostEquivalent(string word1, string word2) {
        auto b1 = bucket_letters(word1);
        auto b2 = bucket_letters(word2);
        for (int i = 0; i < 26; ++i) {
            if (std::abs(b1[i] - b2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};