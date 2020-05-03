int shapeArea(int n) 
{
    int len =  2 * n - 1;
    return len * len - 4 * ( (n * (n - 1)) / 2);
} 
