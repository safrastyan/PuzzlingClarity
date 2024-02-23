class Solution {
public:
    bool is_vowel(char c)
    {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += is_vowel(words[i].front()) && is_vowel(words[i].back())  ? 1 : 0;
        }
        return ans;
    }
};