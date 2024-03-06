class Solution {
public:
    struct Elem 
    {
        Elem(int n, int d, int s): node(n)
                                 , dist(d)
                                 , side(s)
        {}
        int dist;
        int node;
        int side;
        Elem(){}
        
        
    };
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        std::vector<std::vector<std::pair<int, int>>> a(n);
        for (const auto& e: edges) {
            a[e[0]].emplace_back(e[1], e[2]);
            a[e[1]].emplace_back(e[0], e[2]);
        }
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            std::queue<Elem> q;
            std::vector<Elem> dist;
            dist.reserve(n);
            std::vector<char> mark(n, 0);
            mark[i] = 1;
            std::vector<int> sides;
            for (int j = 0; j < a[i].size(); ++j) {
                Elem e(a[i][j].first, a[i][j].second, j);
                q.push(e);
             //   dist.push(e);
                mark[a[i][j].first] = 1;
                sides.push_back(a[i][j].second % signalSpeed == 0 ? 1 : 0);
            }
            
            
            while (!q.empty()) {
                auto e = q.front();
                q.pop();
                for (const auto& new_node: a[e.node]) {
                    int nn = new_node.first;
                    int new_dist = e.dist + new_node.second;
                    if (mark[nn] == 1) {
                        continue;    
                    }
                    
                    Elem new_elem(nn, new_dist, e.side);
                    mark[nn] = 1;
                    q.push(new_elem);
                    if (new_dist % signalSpeed == 0) {
                        ++sides[e.side];
                    }
                }
            }
            
            
            int sum = std::accumulate(sides.begin(), sides.end(), 0);
            int local_ans = 0;
            for (int j = 0; j < sides.size(); ++j) {
                local_ans += sides[j] * (sum - sides[j]);
            }
            ans.push_back(local_ans / 2);
        }
                                        
        return ans;
    }
};