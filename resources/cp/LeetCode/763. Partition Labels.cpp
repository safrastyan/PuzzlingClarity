class Solution {
public:
    vector<int> partitionLabels(string s) {
        static constexpr int INF = 100000;
        std::vector<std::pair<int, int>> inter(26, std::make_pair(INF, INF));
        for (int i = 0; i < 26; ++i) {
            int left = s.find('a' + i);
            if (left == std::string::npos) {
                continue;
            }
            int right = s.rfind('a' + i);
            inter[i] = std::make_pair(left, right);
        }
        std::sort(inter.begin(), inter.end());
        int cur_end = inter.front().second;
        int cur_start = 0;
        std::vector<int> ans;
        for (int i = 1; i < inter.size() && inter[i].first != INF; ++i) {
            if (inter[i].first > cur_end) {
                ans.push_back(cur_end - cur_start + 1);
                cur_start = inter[i].first;
                cur_end = inter[i].second;
                continue;
            }
            cur_end = std::max(cur_end, inter[i].second);
        }
        ans.push_back(cur_end - cur_start + 1);
        return ans;
    }
};