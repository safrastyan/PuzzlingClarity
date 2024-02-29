class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12 + double(minutes) / 60) * 30;
        double d = std::abs(h - minutes * 6);
        return std::min(d, 360 - d);
    }
};