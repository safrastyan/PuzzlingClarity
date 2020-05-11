std::string findEmailDomain(std::string address) 
{
    int f = address.rfind('@');
    return address.substr(f + 1, address.size() - f);
}
