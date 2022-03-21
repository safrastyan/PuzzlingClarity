class Solution {
public:
    
    
    std::map<char , int> roman_chars ={{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

    int roman_to_int(const std::string& n)
    {
        int res = 0;
        for(int i = 0 ; i < n.size()- 1 ; ++i){
            if (roman_chars[n[i]] < roman_chars[n[i+1]]) {
                res -= roman_chars[n[i]];
                continue;
            }
        res += roman_chars[n[i]];
        }
        res += roman_chars[n[n.size()-1]];
        return res;
    }
    
    
    int romanToInt(string s) 
    {
        return roman_to_int(s);
    }
};