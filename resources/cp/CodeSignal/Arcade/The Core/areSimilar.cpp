bool areSimilar(std::vector<int> a, std::vector<int> b) 
{
    std::vector<int> difs;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            difs.push_back(i);
        }
    }
    if (difs.size() == 0) {
        return true;
    }
    if (difs.size() != 2) {
        return false;
    }
    return a[difs[0]] == b[difs[1]] && a[difs[1]] == b[difs[0]];
}

///  a1 a2 a3 ... an
///  b1 b2 b3.....bn

// for every i a[i] == b[i]
// fi exists i a[i] != b[i] -> how many is are there 
// only for 2, i, j a[i] != b[i] a[j] != b[j]   => a[i] == b[j] && a[j] == b[i]
