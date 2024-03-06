class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        char cur;
        while (right - left >= 1 && s[left] == s[right]) {
            cur = s[left];
            for (; left <= right && s[left] == cur; ++left);
            for (; left <= right && s[right] == cur; --right);
        }
        return right - left + 1;
    }
};