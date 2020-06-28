bool is_palindrome(std::string& s)
{
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isCaseInsensitivePalindrome(std::string inputString) 
{
    for (int i = 0; i < inputString.size(); ++i) {
        inputString[i] = std::tolower(inputString[i]);
    }    
    return is_palindrome(inputString);
}
