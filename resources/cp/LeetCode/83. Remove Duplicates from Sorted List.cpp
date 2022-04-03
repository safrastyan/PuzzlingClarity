/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    std::vector<int> list2vec(ListNode* node)
    {
        std::vector<int> res;
        while (node != nullptr) {
            res.push_back(node->val);
            node = node->next;
        }
        return res;
    }
    
    ListNode* vec2list(const std::vector<int>& v)
    {
        ListNode* root = new ListNode(v[0]);
        ListNode* cur = root;
        for (int i = 1; i < v.size(); ++i) {
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }
        return root;
    }
    
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr) {
            return head;
        }
        auto v = list2vec(head);
        auto f = std::unique(v.begin(), v.end());
        v.erase(f, v.end());
        return vec2list(v);
    }
};