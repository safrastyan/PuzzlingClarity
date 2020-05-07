int arrayChange(std::vector<int> inputArray) 
{
    int res = 0;
    for (int i = 0; i < inputArray.size() - 1; ++i) {
        if (inputArray[i + 1] > inputArray[i]) {
            continue;
        }
        res += inputArray[i] - inputArray[i + 1] + 1;;
        inputArray[i + 1] = inputArray[i] + 1;
    }
    return res;
}
