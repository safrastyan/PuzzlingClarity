int arrayMaximalAdjacentDifference(std::vector<int> inputArray) 
{
    int res = -100;
    for (int i = 0; i < inputArray.size() - 1; ++i) {
        res = std::max(res, std::abs(inputArray[i] - inputArray[i + 1]));
    }
    return res;
}
