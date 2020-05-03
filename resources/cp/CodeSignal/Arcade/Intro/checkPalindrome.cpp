bool checkPalindrome(std::string inputString) 
{
    for (int i = 0; i < inputString.size() / 2; ++i) {
        if (inputString[i] != inputString[inputString.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}
