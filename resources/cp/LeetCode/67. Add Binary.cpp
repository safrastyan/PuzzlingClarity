class Solution {
public:
    
    std::string pad(const std::string& a, const std::string& b)
    {
        std::string res(a.size() - b.size(), '0');
        return res + b;
    }
    string addBinary(string a, string b) 
    {
        if (a.size() < b.size()) {
            std::swap(a, b);
        }        
        b = pad(a, b);
        std::cout << a << " " << b << std::endl;
        int car = 0;
        std::string res;
        for (int i = a.size() - 1; i >= 0; --i) {
            int dig = (a[i] - '0') + (b[i] - '0') + car;
            res.push_back('0' + (dig % 2));
            car = dig / 2;
        }
        if (car == 1) {
            res.push_back('1');
        }
        if (car == 2) {
            res += "01";
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    
};