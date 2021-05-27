class Solution {
public:
    
    
    static bool isvowel(char c)
    {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    bool halvesAreAlike(string s) 
    {
        int x = std::count_if(s.begin(), s.begin() + s.size() / 2, isvowel);
        int y = std::count_if(s.begin() + s.size() / 2, s.end(), isvowel);
        return x == y;
    }
};