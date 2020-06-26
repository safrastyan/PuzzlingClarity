std::vector<int> replaceMiddle(std::vector<int> arr) 
{
    if (arr.size() % 2 != 0) {
        return arr;
    }
    int mid = arr[arr.size() / 2 - 1] + arr[arr.size() / 2];
    arr[arr.size() / 2 - 1] = mid;
    arr.erase(arr.begin() + arr.size() / 2, arr.begin() + arr.size() / 2 + 1);
    return arr;
}
