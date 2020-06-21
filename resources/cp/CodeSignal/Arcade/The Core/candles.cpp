int candles(int candlesNumber, int makeNew) 
{
    int res = candlesNumber;
    int left = candlesNumber;
    while (left >= makeNew) {
        int cand = left / makeNew;
        res += cand;
        left -= cand * makeNew;
        left += cand;
    }
    return res;
}
