class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int one = std::count(s.begin(), s.end(), s[0]);
        for (auto c: s) {
            if (std::count(s.begin(), s.end(), c) != one) {
                return false;
            }
        }
        return true;
    }
};