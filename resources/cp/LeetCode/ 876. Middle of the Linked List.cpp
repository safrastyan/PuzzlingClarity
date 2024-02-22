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

    ListNode* middleNode(ListNode* head) {
        auto v = list2vec(head);
        for (int i = 0; i < v.size() / 2; ++i) {
            head = head->next;
        }        
        return head;
    }
};