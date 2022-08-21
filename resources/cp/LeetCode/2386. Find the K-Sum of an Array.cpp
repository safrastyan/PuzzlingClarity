class Solution {
public:
    
    long long kSum(vector<int>& nums, int k) 
    {
        long long pos_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                pos_sum += nums[i];
            }
            nums[i] = std::abs(nums[i]);
        }
        std::sort(nums.begin(), nums.end());
        std::priority_queue<std::pair<long long, int>> q;
        std::vector<long long> res;
        res.push_back(pos_sum);
        q.push(std::make_pair(pos_sum - nums[0], 0));
        while (res.size() != k) {
            auto [sum, ind] = q.top();
            q.pop();
            res.push_back(sum);
            
            if (ind < nums.size() - 1) {
                q.push(std::make_pair(sum - nums[ind + 1], ind + 1));
                q.push(std::make_pair(sum + nums[ind] - nums[ind + 1], ind + 1) );
            }
        }
        
        return res.back();
    }
};