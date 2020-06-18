int arrayPacking(std::vector<int> a) 
{
    int res = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        res <<= 8;
        res += a[i];
    }    
    return res;
}
