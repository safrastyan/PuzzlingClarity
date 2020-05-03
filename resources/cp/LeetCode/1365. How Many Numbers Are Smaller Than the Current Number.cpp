class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        std::vector<int> res;
        for (auto num: nums) {
            int count = 0;
            for (auto temp_num: nums) {
                if (temp_num < num) {
                    ++count;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};