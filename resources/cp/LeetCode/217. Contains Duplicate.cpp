class Solution {
public:
    
    bool containsDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> s;
        for (auto e: nums) {
            if (s.find(e) != s.end()) {
                return true;
            }
            s.insert(e);
        }
        return false;
    }
};