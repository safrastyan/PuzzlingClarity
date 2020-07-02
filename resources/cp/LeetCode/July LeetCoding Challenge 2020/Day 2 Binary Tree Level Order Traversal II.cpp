/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void rec(TreeNode* node, int level, vector<vector<int>>& res)
    {
        if (node == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(std::vector<int>());
        }
        res[level].push_back(node->val);
        rec(node->left, level + 1, res);
        rec(node->right, level + 1, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        rec(root, 0, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
};
