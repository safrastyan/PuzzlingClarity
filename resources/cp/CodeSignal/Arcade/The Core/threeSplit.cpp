int threeSplit(std::vector<int> a) 
{
    std::vector<long long> sums(a.size());
    sums[0] = a[0];
    for (int i = 1; i < a.size(); ++i) {
        sums[i] = sums[i - 1] + a[i];
    }
    int res = 0;
    long long target = sums.back() / 3;
    for (int i = 0; i < a.size() - 2; ++i) {
        for (int j = i + 1; j < a.size() - 1; ++j) {
            long long left = sums[i];
            long long middle = sums[j] - sums[i]; 
            long long right = sums.back() - sums[j];
            if (left == target && middle == target && right == target) {
                ++res;
            }
        }
    }
    return res;
}
