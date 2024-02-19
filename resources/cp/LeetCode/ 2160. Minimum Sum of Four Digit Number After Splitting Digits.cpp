class Solution {
public:

    int minimumSum(int num) {
        std::vector<int> d;
        for (int i = 0; i < 4; ++i) {
            d.push_back(num % 10);
            num /= 10;
        }
        std::sort(d.begin(), d.end());
        return d[0] * 10 + d[3] + d[1] * 10 + d[2];
    }
};