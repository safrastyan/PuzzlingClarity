class Solution {
public:
    
    bool is_sign(char c)
    {
        return c == '-' || c == '+';
    }
    
    bool is_e(char c)
    {
        return c == 'e' || c == 'E';
    }
    
    bool sanity(const std::string& s)
    {
        if (s.size() == 1 && !std::isdigit(s.front())) {
            return false;
        }
        if (s.size() == 1) {
            return true;
        }
        
        if (!std::isdigit(s[0]) && !std::isdigit(s[1])) {
            if (s.size() == 2) {
                return false;
            }
            if (!(is_sign(s[0]) && s[1] == '.')) {
                return false;
            }
        }
        for (auto c: s) {
            if (!std::isdigit(c) && !is_e(c) && !is_sign(c) && c != '.') {
                return false;
            }
        }
        return true;
    }
    
    bool sign(const std::string& s)
    {
        
        if (is_sign(s[0]) && is_e(s[1])) {
            return false;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (is_sign(s[i]) && (!is_e(s[i - 1]) || i == s.size() - 1 || s[i + 1] == '.')) {
                return false;
            }
        }
        return true;
    }
    
    
    int dot(const std::string& s)
    {
        int c = std::count(s.begin(), s.end(), '.');
        if (c > 1) {
            return -2;
        }
        if (c == 0) {
            return -1;
        }
        
        if (s.size() == 1) {
            return -2;
        }
        return s.find('.');
    }
    
    int E(const std::string& s)
    {
        int c = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (is_e(s[i])) {
                ++c;
                res = i;
            }
        }
        if (c > 1) {
            return -2;
        }
        if (c == 0) {
            return -1;
        }
        return res;
    }
    
    bool isNumber(string s) 
    {
        if (!sanity(s)) {
            return false;
        }   
        std::cout << "sanity " << std::endl;
        
        if (!sign(s)) {
            return false;
        }
        std::cout << "sign " << std::endl;
        
        int d = dot(s);
        if (d ==  -2) {
            return false;
        }
        std::cout << "dot " << std::endl;
        
        int e = E(s);
        std::cout << "E" << std::endl;
        
        if (e == -2) {
            return false;
        }
        std::cout << d << " " << e << std::endl;
        
        if (e == s.size() - 1 || e == 0) {
            return false;
        }
        if (e == 1 && d == 0) {
            return false;
        }
        if (e == -1) {
            return true;
        }
        
        if (e >= 0 && d == -1) {
            return true;
        }
        if (e == -1 && d >= 0) {
            return true;
        }
        
        if (d > e) {
            return false;
        }
        
        
        
        
        return true;
    }
};