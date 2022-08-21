class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cur_free = 1;
        int cur_num = nums[0];
        int cur_count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == cur_num) {
                ++cur_count;
            } else {
                cur_count = 1;
                cur_num = nums[i];
            }
            if (cur_count <= 2) {
                nums[cur_free] = cur_num;
                ++cur_free;
            }
        }
        return cur_free;
    }
};