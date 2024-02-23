class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = std::count(moves.begin(), moves.end(), 'L');
        int r = std::count(moves.begin(), moves.end(), 'R');
        return std::max(l, r) + moves.size() - l - r - std::min(l, r);
    }
};