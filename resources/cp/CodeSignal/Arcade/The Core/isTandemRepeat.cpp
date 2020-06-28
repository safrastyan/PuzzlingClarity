bool isTandemRepeat(std::string inputString) 
{
    if (inputString.size() % 2 == 1) {
        return false;
    }
    auto half = inputString.substr(0, inputString.size() / 2);
    return half + half == inputString;
}
