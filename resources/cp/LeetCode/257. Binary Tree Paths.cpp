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
    void rec(TreeNode* root, std::vector<std::string>& ans, std::string& cur) {
        if (root->left == nullptr && root->right == nullptr) {
            auto temp = cur;
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        if (root->left != nullptr) {
            auto temp = cur;
            cur += std::to_string(root->left->val) + "->";
            rec(root->left, ans, cur);
            cur = temp;
        }
        
        if (root->right != nullptr) {
            auto temp = cur;
            cur += std::to_string(root->right->val) + "->";
            rec(root->right, ans, cur);
            cur = temp;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ans;
        std::string cur;
        cur = std::to_string(root->val) + "->";
        rec(root, ans, cur);
        return ans;
    }
};