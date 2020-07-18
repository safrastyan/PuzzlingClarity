std::string characterParity(char symbol) 
{
    if (!std::isdigit(symbol)) {
        return "not a digit";
    }
    return (symbol - '0') % 2 == 0 ? "even" : "odd"; 
}
