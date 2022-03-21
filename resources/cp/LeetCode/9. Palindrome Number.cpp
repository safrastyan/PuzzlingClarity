class Solution {
public:
    
    bool is_palindrome(const std::string& s)
    {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int x) 
    {
        return is_palindrome(std::to_string(x));
    }
};