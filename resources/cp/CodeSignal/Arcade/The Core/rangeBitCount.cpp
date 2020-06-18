int bcount(int x)
{
    int res = 0;
    while (x != 0) {
        res += x % 2;
        x /= 2;
    }
    return res;
}

int rangeBitCount(int a, int b) 
{
    int res = 0;
    for (int i = a; i <= b; ++i) {
        res += bcount(i);
    }
    return res;
}
