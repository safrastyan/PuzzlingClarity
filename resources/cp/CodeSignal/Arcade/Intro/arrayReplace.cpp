std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem) {
    for (int i = 0; i < inputArray.size(); ++i) {
        if (inputArray[i] == elemToReplace) {
            inputArray[i] = substitutionElem;
        }
    }
    return inputArray;
}
