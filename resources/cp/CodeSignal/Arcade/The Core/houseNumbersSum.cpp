int houseNumbersSum(std::vector<int> inputArray) 
{
    int res = 0;
    for (auto c: inputArray) {
        if (c == 0) {
            break;
        }
        res += c;
    }
    return res;
}
