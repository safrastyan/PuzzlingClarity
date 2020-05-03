class Solution {
public:
    
    int digs2num(std::vector<int>& digs)
    {
        int ten = 1;
        int res = 0;
        for (auto d: digs) {
            res += d * ten;
            ten *= 10;
        }
        return res;
    }
    
    std::vector<int> num2digs(int n)
    {
        std::vector<int> res;
        while (n != 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    
    int maximum69Number (int num) 
    {
        auto digs = num2digs(num);
        for (int i = digs.size() - 1; i >= 0; --i) {
            if (digs[i] == 6) {
                digs[i] = 9;
                break;
            }
        }
        return digs2num(digs);
    }
};