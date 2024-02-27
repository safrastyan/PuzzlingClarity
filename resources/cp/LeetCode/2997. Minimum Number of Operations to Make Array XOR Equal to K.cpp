class Solution {
public:
    std::string full_binary(int num, int length)
    {
        std::string s(length, '0');
        int i = 0;
        while (num != 0) {
            s[i] = '0' + num % 2;
            num /= 2;
        ++i;
        }
        return s;
    }

    int hamming_distance(const std::string& s1, const std::string& s2)
    {
        assert(s1.size() == s2.size());
        int res = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++res;
            }
        }
        return res;
    }

    int minOperations(vector<int>& nums, int k) {
        int n = 0;
        for (auto num: nums) {
            n ^= num;
        }
        return hamming_distance(full_binary(n, 32), full_binary(k, 32));
    }
};