class Solution {
public:
    string defangIPaddr(string address) 
    {
        std::string res;
        for (int i = 0; i < address.size(); ++i) {
            if (address[i] == '.') {
                res += "[.]";
            } else {
                res.push_back(address[i]);
            }
        }
        return res;
    }
};