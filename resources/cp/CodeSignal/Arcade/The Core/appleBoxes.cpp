int appleBoxes(int k) 
{
    int r = 0, y = 0;
    for (int i = 1; i <= k; ++i) {
        if (i % 2 == 1) {
            y += i * i;
        } else {
            r += i * i;
        }
    }
    return r - y;
}
