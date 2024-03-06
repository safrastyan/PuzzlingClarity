class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> a1;
        std::vector<int> a2;
        
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            if (a1.back() > a2.back()) {
                a1.push_back(nums[i]);
                continue;
            }
            a2.push_back(nums[i]);
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};