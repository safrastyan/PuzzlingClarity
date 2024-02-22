class Solution {
public:
    std::string to_base(int n, int b)
    {
        std::string res;
        while (n != 0) {
            int r = n % b;
            res.push_back(r < 10 ? static_cast<char>(r + '0') : static_cast<char>(r + 'A' - 10));
            n /= b;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    vector<int> sortByBits(vector<int>& arr) {
        bool bubble = true;
        while (bubble) {
            bubble = false;
            for (int i = 0; i < arr.size() - 1; ++i) {
                auto b = to_base(arr[i], 2);
                auto d1 = std::count(b.begin(), b.end(), '1');
                b = to_base(arr[i + 1], 2);
                auto d2 = std::count(b.begin(), b.end(), '1');
                if (d1 > d2 || (d1 == d2 && arr[i] > arr[i + 1])) {
                    std::swap(arr[i], arr[i + 1]);
                    bubble = true;
                }
            }
        }        
        return arr;
    }
};