std::string findEmailDomain(std::string address) 
{
    int pos = address.rfind('@');
    return address.substr(pos + 1, address.size() - pos);
}
