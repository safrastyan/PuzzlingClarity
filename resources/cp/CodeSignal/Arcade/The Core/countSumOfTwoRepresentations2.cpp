int countSumOfTwoRepresentations2(int n, int l, int r) 
{
    int half = n / 2;
    if (half > r || half < l) {
        return 0;
    }
    int ans = std::min(half - l, r - half);
    return ans + (n % 2 == 0 ? 1 : 0);
}
