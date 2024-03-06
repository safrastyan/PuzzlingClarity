class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long> q;
        for (auto elem: nums) {
            q.push(-elem);
        }
        int ans = 0;
        while (q.size() >= 2) {
            auto t1 = -q.top();
            if (t1 >= k) {
                break;
            }
            q.pop();
            auto t2 = -q.top();
            q.pop();
            q.push(-(std::min(t1, t2) * 2 + std::max(t1, t2)));
            ++ans;
        }
        return ans;
    }
};