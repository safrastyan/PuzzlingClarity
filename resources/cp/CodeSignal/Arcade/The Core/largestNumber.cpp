int largestNumber(int n) 
{
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res *= 10;
        res += 9;
    }
    return res;
}
