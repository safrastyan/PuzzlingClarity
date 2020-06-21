class Solution {
public:
    string generateTheString(int n) 
    {
        return n % 2 == 0 ? std::string(n - 1, 'a') + "b" : std::string(n, 'a');    
    }
};