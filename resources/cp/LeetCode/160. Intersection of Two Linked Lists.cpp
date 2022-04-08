/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        std::set<ListNode*> all;
        ListNode* t = headA;
        while (t != nullptr) {
            all.insert(t);
            t = t->next;
        }
        t = headB;
        while (t != nullptr) {
            if (all.find(t) != all.end()) {
                return t;
            }
            t = t->next;
        }
        return nullptr;
    }
};