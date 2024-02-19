class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < score.size() - 1; ++i) {
                for (int j = i + 1; j < score.size(); ++j) {
                    if (score[i][k] < score[j][k]) {
                        done = false;
                        std::swap(score[i], score[j]);
                        break;
                    }
                }
            }
        }
        return score;
    }
};