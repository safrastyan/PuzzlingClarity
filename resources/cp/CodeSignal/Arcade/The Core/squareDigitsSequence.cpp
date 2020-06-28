int sqSum(int x)
{
    int res = 0;
    while (x != 0) {
        int dig = x % 10;
        res += dig * dig;
        x /= 10;
    }
    return res;
}

int squareDigitsSequence(int a0) 
{
    std::set<int> a;
    a.insert(a0);
    a0 = sqSum(a0);
    while (a.find(a0) == a.end() ) {
        a.insert(a0);
        a0 = sqSum(a0);
    }    
    return a.size() + 1;
}
