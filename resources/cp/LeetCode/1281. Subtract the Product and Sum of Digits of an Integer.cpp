class Solution {
public:
    
    std::vector<int> digits(int n)
    {
        std::vector<int> res;
        while (n != 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    
    int subtractProductAndSum(int n) 
    {
        int prod = 1, sum = 0;
        auto dig = digits(n);
        for (auto d: dig) {
            prod *= d;
            sum += d;
        }
        return prod - sum;
    }
};