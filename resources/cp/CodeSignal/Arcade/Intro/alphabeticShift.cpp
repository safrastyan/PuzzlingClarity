std::string alphabeticShift(std::string inputString) 
{
    for (int i = 0; i < inputString.size(); ++i) {
        if (inputString[i] == 'z') {
            inputString[i] = 'a';
            continue;
        }
        ++inputString[i];
    }
    return inputString;
}
