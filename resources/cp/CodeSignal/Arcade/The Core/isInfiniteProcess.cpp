bool isInfiniteProcess(int a, int b) 
{
    if (a > b) {
        return true;
    }
    
    return a % 2 != b % 2;
}
