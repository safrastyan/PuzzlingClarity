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
    
    std::vector<int> list2vec(ListNode* a)
    {
        std::vector<int> res;
        while (a != nullptr) {
            res.push_back(a->val);
            a = a->next;
        }
        return res;
    }
    

    ListNode* vec2list(const std::vector<int>& v)
    {
        ListNode* head = new ListNode(v[0]);
        ListNode* n = head;
        for (auto i = 1; i < v.size(); ++i) {
            n->next = new ListNode(v[i]);
            n = n->next;
        }
        return head;
    }
    
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head == nullptr) {
            return nullptr;
        }
        auto v = list2vec(head);
        std::vector<int> res;
        for (auto elem: v) {
            if (elem != val) {
                res.push_back(elem);
            }
        }
        if (res.empty()) {
            return nullptr;
        }
        return vec2list(res);
    }
};