class Solution {
public:
    
    std::string to_range(const std::vector<int>& a, int left, int right)
    {
        if (left == right) {
            return std::to_string(a[left]);
        }
        return std::to_string(a[left]) + "->" + std::to_string(a[right]);
    }
    vector<string> summaryRanges(vector<int>& nums) 
    {
        std::vector<std::string> res;
        if (nums.empty()) {
            return res;
        }
        int left = 0;
        int right = 0;
        while (true) {
            if (right == nums.size() - 1) {
                res.push_back(to_range(nums, left, right));
                break;
            }
            ++right;
            if (nums[right] != nums[right - 1] + 1) {
                res.push_back(to_range(nums, left, right - 1));
                left = right;
            }
        }
        
        return res;
    }
};