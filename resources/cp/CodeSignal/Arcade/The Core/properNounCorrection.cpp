std::string properNounCorrection(std::string noun)
{
    for (int i = 1; i < noun.size(); ++i) {
        noun[i] = std::tolower(noun[i]);
    }
    noun[0] = std::toupper(noun[0]);
    return noun;
}
