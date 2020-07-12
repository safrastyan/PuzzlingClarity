bool isUnstablePair(std::string filename1, std::string filename2) 
{
    std::string s1 = filename1;
    std::string s2 = filename2;
    for (int i = 0; i < s1.size(); ++i) {
        s1[i] = std::towlower(s1[i]);
    }
    
    for (int i = 0; i < s2.size(); ++i) {
        s2[i] = std::tolower(s2[i]);
    }
    
    return s1 < s2 != filename1 < filename2;
}
