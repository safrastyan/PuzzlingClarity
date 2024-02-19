// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long p = 1;
        long long q = n;
        while (q - p > 1) {
            auto mid = (p + q) / 2;
            if (isBadVersion(mid)) {
                q = mid;
            } else {
                p = mid;
            }
        }
        if (isBadVersion(p)) {
            return p;
        }
        return q;
    }
};