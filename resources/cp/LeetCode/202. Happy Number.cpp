class Solution {
public:
    
    int next(int n)
    {
        int res = 0;
        while (n != 0) {
            int dig = n % 10;
            res += dig * dig;
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) 
    {
        if (n == 1) {
            return true;
        }
        std::set<int> s;
        s.insert(n);
        while (true) {
            auto nn = next(n);
            if (nn == 1) {
                return true;
            }
            if (s.find(nn) != s.end()) {
                return false;
            }
            s.insert(nn);
            n = nn;
        }
        return true;
    }
};