class Solution {
public:
    
    int arraySign(vector<int>& nums) 
    {
        if (std::find(nums.begin(), nums.end(), 0) != nums.end()) {
            return 0;
        }
        
        if (std::count_if(nums.begin(), nums.end(), [](int n) { return n < 0; }) % 2 == 1) {
            return -1;
        }
        return 1;
    }
};