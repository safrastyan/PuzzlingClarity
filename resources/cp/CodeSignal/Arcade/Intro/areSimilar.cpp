std::vector<int> get_indices(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<int> indices;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            indices.push_back(i);
        }
    }
    return indices;
}

bool areSimilar(std::vector<int> a, std::vector<int> b) 
{
    auto ind = get_indices(a, b);
    if (ind.size() >= 3) {
        return false;
    }
    if (ind.size() == 0) {
        return true;
    }
    if (ind.size() == 1) {
        return false;
    }

    return a[ind[0]] == b[ind[1]] && a[ind[1]] == b[ind[0]];
}
