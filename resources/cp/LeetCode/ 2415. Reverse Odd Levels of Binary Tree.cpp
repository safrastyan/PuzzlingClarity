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

    std::vector<TreeNode*> next(const std::vector<TreeNode*>& nodes)
    {
        std::vector<TreeNode*> res;
        for (auto* n: nodes) {
            res.push_back(n->left);
            res.push_back(n->right);
        }
        return res;
    }



    TreeNode* reverseOddLevels(TreeNode* root) {
        std::vector<TreeNode*> cur{root};
        bool even = false;
        while (true) {
            cur = next(cur);
            if (cur[0] == nullptr) {
                break;
            }
            if (!even) {
                for (int i = 0; i < cur.size() / 2; ++i) {
                    std::swap(cur[i]->val, cur[cur.size() - i - 1]->val);
                }
            }
            even = !even;
        }
        return root;
    }  
};