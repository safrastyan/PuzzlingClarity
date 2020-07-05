class Solution {
public:
    int nthUglyNumber(int n) 
    {  
        std::vector<int> res(1, 1);
                
        int two = 0;
        int three = 0;
        int five= 0;
        
        while (res.size() < n) {
            int cur = std::min(res[two] * 2, std::min(res[three] * 3, res[five] * 5));
            if (cur == res[two] * 2) {
                ++two;
            } 
            if (cur == res[three] * 3) {
                    ++three;
            }
            if (cur == res[five] * 5) {
                ++five;    
            }
            res.push_back(cur);
        }
        
        return res.back();
    }
};