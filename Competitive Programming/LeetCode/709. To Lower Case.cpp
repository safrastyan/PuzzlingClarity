class Solution {
public:
    char toLower(char c)
    {
        if (!(c >= 'A' && c <= 'Z')) {
            return c;
        }
        return 'a' + (c - 'A');
    }
    
    string toLowerCase(string str) 
    {
        std::string res;
        for (int i = 0; i < str.size(); ++i) {
            res.push_back(toLower(str[i]));
        }
        return res;
    }
};