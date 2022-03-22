class Solution {
public:
    
    bool match(char c1, char c2)
    {
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
    
    bool isValid(string s) 
    {
        std::stack<char> a;
        for (auto elem: s) {
            if (a.empty()) {
                a.push(elem);
                continue;
            }
            
            auto top = a.top();
            a.pop();
            if (match(top, elem)) {
                continue;
            }
            a.push(top);
            a.push(elem);
        }
        
        return a.empty();
    }
};