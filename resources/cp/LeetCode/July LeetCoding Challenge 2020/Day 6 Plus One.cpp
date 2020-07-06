class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        ++digits[digits.size() -1];
        for (int i = digits.size() - 1; i > 0; --i) {
            digits[i - 1] += digits[i] / 10;
            digits[i] %= 10;
        }
        if (digits[0] == 10) {
            digits.insert(digits.begin(), 1);
            digits[1] = 0;
        }
        return digits;
    }
};