class Solution {
public:
    int minPartitions(string n) {
        return *std::max_element(n.begin(), n.end()) - '0';
    }
};