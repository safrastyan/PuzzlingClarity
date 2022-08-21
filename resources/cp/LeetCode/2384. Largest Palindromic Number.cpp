class Solution {
public:
    string largestPalindromic(string num) {
        std::vector<int> cnts(10, 0);
        for (auto c: num) {
            ++cnts[c - '0'];
        }
        
        ///take evens
        std::string half;
        for (int i = 9; i >= 1; --i) {
            if (cnts[i] > 1) {
                int len = cnts[i] / 2;
                half += std::string(len, '0' + i);
                cnts[i] -= len * 2;
            }
        }
        
        //check if middle
        std::string mid;
        for (int i = 9; i >= 0; --i) {
            if (cnts[i] >= 1) {
                mid.push_back('0' + i);
                --cnts[i];
                break;
            }
        }
        
        std::string res;
        if (!half.empty()) {
            half += std::string(cnts[0] / 2, '0'); 
        }
        auto rhalf = half;
        std::reverse(rhalf.begin(), rhalf.end());
        res = half + mid + rhalf;
        if (res.empty()) {
            return "0";
        }
        return res;
    }
};