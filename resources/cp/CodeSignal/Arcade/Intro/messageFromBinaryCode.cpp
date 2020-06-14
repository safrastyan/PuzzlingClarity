std::string messageFromBinaryCode(std::string code) 
{
    std::string res;
    for (int i = 0; i < code.size() / 8; ++i) {
        int num = 0;
        for (int j = i * 8; j < (i +1 ) * 8; ++j) {
            int bit = code[j] - '0';
            num += bit * ( 1 << ((i +1) * 8 - j - 1) );
        }
        res.push_back(static_cast<char>(num));
    }
    return res;
}
