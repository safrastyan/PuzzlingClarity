int absoluteValuesSumMinimization(std::vector<int> a) 
{
    return a[a.size() % 2 == 0 ? a.size() / 2 -1 : a.size() / 2];
}
