int electionsWinners(std::vector<int> votes, int k) 
{
    int max = *std::max_element(votes.begin(), votes.end());
    if (k == 0) {
        if (std::count(votes.begin(), votes.end(), max) > 1) {
            return 0;
        }
        return 1;
    }
    int res = 0;
    for (auto c: votes) {
        if (c + k > max) {
            ++res;
        }
    }
    return res;
}
