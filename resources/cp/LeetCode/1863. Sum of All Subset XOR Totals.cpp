class Solution {
public:

template<typename T>
std::vector<std::vector<T>> generate_all_subsets(const std::vector<T>& a)
{
    std::vector<std::vector<T>> res;

    for (int i = 0; i < (1 << a.size()); ++i) {
        std::vector<char> mask(a.size());
        std::vector<T> cur_res;

        int n = i;
        int j = 0;
        while (n != 0) {
            mask[j] = n % 2;
            n /= 2;
            ++j;    
        }
        for (int j = 0; j < mask.size(); ++j) {
            if (mask[j] == 1) {
                cur_res.push_back(a[j]);
            }
        }
        res.push_back(cur_res);
    }
    return res;
    ///TODO make this to use the full_binary from Numbers module
}

    int subsetXORSum(vector<int>& nums) {
        auto ss = generate_all_subsets(nums);
        int ans = 0;
        for (auto& a: ss) {
            int x = 0;
            for (auto elem: a) {
                x ^= elem;
            }
            ans += x;
        }
        return ans;
    }
};