int phoneCall(int min1, int min2_10, int min11, int s) 
{
    int res = 0;
    if (s < min1) {
        return 0;
    }
    ++res;
    s -= min1;
  
    if (s < 9 * min2_10) {
        return res + s / min2_10;
    }
    res += 9;
    s -= min2_10 * 9;
    
    return res + s / min11;
}
