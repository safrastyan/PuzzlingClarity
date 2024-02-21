class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::queue<int> q;
        for (int i = 0; i < deck.size(); ++i) {
            q.push(i);
        }
        std::vector<int> order;
        bool reveal = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (reveal) {
                order.push_back(t);
            } else {
                q.push(t);
            }
            reveal = !reveal;
        }
        std::sort(deck.begin(), deck.end());
        std::vector<int> res(deck.size());
        for (int i = 0; i < order.size(); ++i) {
            res[order[i]] = deck[i];
        }
        return res;
    }
};