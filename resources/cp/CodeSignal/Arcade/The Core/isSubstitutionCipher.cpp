bool check(std::string string1, std::string string2)
{
    std::vector<int> cypher(27, 0);
    for (int i = 0; i < string1.size(); ++i) {
        int cur = string1[i] - 'a' + 1;
        int mapped = string2[i] - 'a' + 1;
        if (cypher[cur] == 0) {
            cypher[cur] = mapped;
            continue;
        }
        if (cypher[cur] != mapped) {
            return false;
        }
    }
    return true;
}

bool isSubstitutionCipher(std::string string1, std::string string2) 
{
    return check(string1, string2) && check(string2, string1);
}

/// s1, s2
/// cypher(c1) -> c2

///  for c from s1, mapping is correct 
///  shouldn't be any i, j where i != j, cypher(s1[i]) = s2[i] cypher(s1[j]) = s2[j] and s2[i] != s2[j] but s1[i] == s1[j]