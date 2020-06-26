bool isSmooth(std::vector<int> arr) 
{
    return (arr.front()  == (arr.size() % 2 == 0 ? arr[arr.size() / 2] + arr[arr.size() / 2 - 1] : arr[arr.size() / 2])) && arr.front() == arr.back();
}
