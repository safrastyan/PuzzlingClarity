class Solution {
public:
    
    std::vector<std::pair<int, std::string>> int_roman_map{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
                                                    {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };    
    std::string int_to_roman(int n) 
    {
        std::string res;
        for (int i = 0; n != 0; ++i) {
            auto r = int_roman_map[i];
            int c = n / r.first;
            n %= r.first;
            for (int j = 0; j < c; ++j) {
                res += r.second;
            }
        }
        return res;
    }   
    
    string intToRoman(int num) 
    {
        return int_to_roman(num);    
    }
};