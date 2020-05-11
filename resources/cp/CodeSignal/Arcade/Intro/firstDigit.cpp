char firstDigit(std::string inputString) 
{
    for (int i = 0; i < inputString.size(); ++i) {
        if (std::isdigit(inputString[i])) {
            return inputString[i];
        }
    }
    return '-';
}
