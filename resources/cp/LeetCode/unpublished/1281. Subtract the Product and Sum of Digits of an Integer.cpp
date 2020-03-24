class Solution {
public:
    vector<int> digits(int n)
    {
        vector<int> res;
        while (n != 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    
    int subtractProductAndSum(int n) 
    {
        auto digs = digits(n);
        int p = 1, s = 0;
        for (auto d: digs) {
            p *= d;
            s += d;
        }
        return p - s;
    }
};