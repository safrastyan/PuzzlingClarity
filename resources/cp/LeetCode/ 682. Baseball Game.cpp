class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> res;
        for (auto& o: operations) {
            if (o == "+") {
                res.push_back(res.back() + res[res.size() - 2]);
                continue;
            }
            if (o == "D") {
                res.push_back(res.back() * 2);
                continue;
            }
            if (o == "C") {
                res.pop_back();
                continue;
            }
            res.push_back(std::stoi(o));
        }
        return std::accumulate(res.begin(), res.end(), 0);
    }
};