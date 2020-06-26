std::vector<int> firstReverseTry(std::vector<int> arr) 
{
    if (arr.size() < 2) {
        return arr;
    }
    int t = arr[0];
    arr[0] = arr.back();
    arr[arr.size() - 1] = t;
    return arr;
}
