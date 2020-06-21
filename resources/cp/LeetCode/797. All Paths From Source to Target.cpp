class Solution {
public:
    
    void rec(const vector<vector<int>>& graph, vector<vector<int>>& ans, std::vector<int>& cur_path, int cur_node)
    {
        if (cur_node == graph.size() - 1) {
            ans.push_back(cur_path);
            return;
        }
        for (int i = 0; i < graph[cur_node].size(); ++i) {
            int node = graph[cur_node][i];
            cur_path.push_back(node);
            rec(graph, ans, cur_path, node);
            cur_path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> cur_path;
        cur_path.push_back(0);
        rec(graph, ans, cur_path, 0);
        return ans;
    }
};