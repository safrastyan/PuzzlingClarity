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
    
    std::vector<int> list_to_vec(ListNode* n)
    {
        std::vector<int> res;
        while (n != nullptr) {
            res.push_back(n->val);
            n = n->next;
        }
        return res;
    }
    
    ListNode* vec_to_list(const std::vector<int>& v)
    {
        if (v.empty()) {
            return nullptr;
        }
        ListNode* h = new ListNode(v[0]);
        ListNode* n = h;
        for (int i = 1; i < v.size(); ++i) {
            n->next = new ListNode(v[i]);
            n = n->next;
        }
        return h;
    }

    ListNode* swapPairs(ListNode* head) 
    {
        if (head == nullptr) {
            return nullptr;
        }
        auto v = list_to_vec(head);
        for (int i = 0; i < v.size() / 2; ++i) {
            std::swap(v[2 * i], v[2 * i + 1]);
        }
        return vec_to_list(v);
    }
};