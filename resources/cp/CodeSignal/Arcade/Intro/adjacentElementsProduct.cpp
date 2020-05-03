int adjacentElementsProduct(std::vector<int> inputArray) 
{
    int ans = inputArray[0] * inputArray[1];
    for (int i = 1; i < inputArray.size() - 1; ++i) {
        ans = std::max(ans, inputArray[i] * inputArray[i + 1]);
    }
    return ans;
}
