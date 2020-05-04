std::vector<int> sortByHeight(std::vector<int> a) 
{
    std::vector<int> people;
    for (auto elem: a) {
        if (elem != -1) {
            people.push_back(elem);
        }
    }

    std::sort(people.begin(), people.end());
    int cur_ind = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != -1) {
            a[i] = people[cur_ind];
            ++cur_ind;
        }
    }
    return a;
}
