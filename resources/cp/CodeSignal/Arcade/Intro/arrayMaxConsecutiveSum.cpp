int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k) 
{
    int res = 0;
    for (int i = 0; i < k; ++i) {
        res += inputArray[i];
    }
    int cur = res;
    for (int i = 1; i < inputArray.size() - k + 1; ++i) {
        cur -= inputArray[i - 1];
        cur += inputArray[i + k - 1];
        res = std::max(res, cur);
    }
    return res;
}
