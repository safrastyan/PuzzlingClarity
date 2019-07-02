class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string n = std::to_string(x);
        for (int i = 0; i < n.size() / 2; ++i) {
            if (n[i] != n[n.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};