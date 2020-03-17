class Solution {
public:
    
    vector<int> get_digits(int x)
    {
        vector<int> digs;
        while (x != 0) {
            digs.push_back(x % 10);
            x /= 10;
        }
        return digs;
    }
    
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            auto digs = get_digits(i);
            bool is_sd = true;
            for (int j = 0; j < digs.size(); ++j) {
                if (digs[j] == 0) {
                    is_sd = false;
                    break;
                }
                if (i % digs[j] != 0) {
                    is_sd = false;
                    break;
                }
            }
            if (is_sd) {
                res.push_back(i);
            }
        }
        return res;
    }
};