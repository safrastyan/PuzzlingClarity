class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        std::vector<int> res;
        for (auto elem: nums) {
            if (elem == val) {
                continue;
            }
            res.push_back(elem);
        }
        nums = res;
        return nums.size();
    }
};