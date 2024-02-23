class Solution {
public:
    int percentageLetter(string s, char letter) {
        return (std::count(s.begin(), s.end(), letter) * 100) / s.size();
    }
};