class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        std::istringstream iss(s);
        std::string cur;
        std::string last;
        while (iss >> cur) {
            last = cur;
        }
        return last.size();
    }
};