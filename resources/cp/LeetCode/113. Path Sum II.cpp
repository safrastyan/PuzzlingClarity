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
    void rec(TreeNode* node, std::vector<std::vector<int>>& ans, std::vector<int>& cur, int cur_sum, int target)
    {
        
        if (node->left == nullptr && node->right == nullptr) {
            if (target == cur_sum) {
                ans.push_back(cur);
            }
            return;
        }

        if (node->left != nullptr) {
            cur.push_back(node->left->val);
            cur_sum += node->left->val;
            rec(node->left, ans, cur, cur_sum, target);
            cur_sum -= node->left->val;
            cur.pop_back();
        }

        if (node->right != nullptr) {
            cur.push_back(node->right->val);
            cur_sum += node->right->val;
            rec(node->right, ans, cur, cur_sum, target);
            cur_sum -= node->right->val;
            cur.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return std::vector<std::vector<int>>{};
        }
        std::vector<std::vector<int>> ans;

        std::vector<int> cur{root->val};
        int cur_sum = root->val;
        rec(root, ans, cur, cur_sum, targetSum);
        return ans;
    }
};