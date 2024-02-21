class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < names.size() - 1; ++i) {
                if (heights[i] < heights[i + 1]) {
                    std::swap(names[i], names[i + 1]);
                    std::swap(heights[i], heights[i + 1]);
                    done = false;
                }
            }
        }
        return names;
    }
};