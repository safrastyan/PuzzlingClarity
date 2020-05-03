bool check(const std::vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] >= v[i + 1]) {
            return false;
        }
    }
    return true;
}

bool almostIncreasingSequence(std::vector<int> sequence) 
{
    for (int i = 0; i < sequence.size() - 1; ++i) {
        if (sequence[i] >= sequence[i + 1]) {
            auto left = sequence;
            auto right = sequence;
            left.erase(left.begin() + i);
            right.erase(right.begin() + i + 1);
            return check(left) || check(right);
        }
    }

    return true;
}
