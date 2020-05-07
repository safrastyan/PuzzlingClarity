bool variableName(std::string name) 
{
    if (std::isdigit(name[0])) {
        return false;
    }
    for (auto c: name) {
        if (!std::isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}
