class Solution {
public:
    
    std::vector<int> bits(int x)
    {
        std::vector<int> res(32, 0);
        int i = 0;
        while (x != 0) {
            res[i] = x % 2;
            x /= 2;
            ++i;
        }
        return res;
    }
    
    int hammingDistance(int x, int y) 
    {
        auto bx = bits(x);
        auto by = bits(y);
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (bx[i] != by[i]) {
                ++res;
            }
        }
        return res;
    }
};
