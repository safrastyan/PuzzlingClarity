std::string reflectString(std::string inputString) 
{
    for (int i = 0; i < inputString.size(); ++i) {
        inputString[i] = 'a' + (25 - (inputString[i] - 'a'));
    }
    return inputString;
}
