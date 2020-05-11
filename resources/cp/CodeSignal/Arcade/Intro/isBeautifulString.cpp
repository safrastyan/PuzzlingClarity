bool isBeautifulString(std::string inputString) 
{
    int cur = std::count(inputString.begin(), inputString.end(), 'a');
    for (int i = 1; i < 26; ++i) {
        int temp = std::count(inputString.begin(), inputString.end(), 'a' + i);
        if (temp > cur) {
            return false;
        }
        cur = temp;
    }
    return true;
}
