int digsum(int x)
{
    int res = 0;
    while (x != 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

bool comfortable(int a, int b)
{
    return b >= a - digsum(a) && b <= a + digsum(a);
}

int comfortableNumbers(int l, int r) 
{
    int res = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            if (comfortable(i,  j) && comfortable(j, i)) {
                ++res;
            }
        }
    }        
    return res;
}

