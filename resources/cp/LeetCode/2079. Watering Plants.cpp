class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 1;
        int pos = -1;
        int bucket = capacity;
        for (int i = 0; i < plants.size() - 1; ++i) {
            if (bucket >= plants[i]) {
                bucket -= plants[i];
            }
            if (bucket < plants[i + 1]) {
                ans += 2 * (i + 1);
                bucket = capacity;
            }
            ++ans;
        }
        return ans;
    }
};