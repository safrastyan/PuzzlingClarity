class Solution {
public:
    int dist(char c1, char c2)
    {
        if (c1 > c2) {
            std::swap(c1, c2);
        }
        return std::min(c2 - c1, c1 + 26 - c2);
    }
    int minTimeToType(string word) {
        int ans = 0;
        word = std::string("a") + word;
        for (int i = 0; i < word.size() - 1; ++i) {
            ans += dist(word[i], word[i + 1]);
        }
        return ans + word.size() - 1;
    }
};