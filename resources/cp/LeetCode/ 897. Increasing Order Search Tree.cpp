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

    void collect(TreeNode* node, std::vector<int>& elems)
    {
        if (node == nullptr) {
            return;
        }
        elems.push_back(node->val);
        collect(node->left, elems);
        collect(node->right, elems);
    }

    TreeNode* increasingBST(TreeNode* root) {
        std::vector<int> elems;
        collect(root, elems);
        std::sort(elems.begin(), elems.end());
        TreeNode* ans = new TreeNode(elems.front());
        TreeNode* head = ans;
        for (int i = 1; i < elems.size(); ++i) {
            TreeNode* new_node = new TreeNode(elems[i]);
            head->right = new_node;
            head = new_node;
        }
        return ans;
    }
};