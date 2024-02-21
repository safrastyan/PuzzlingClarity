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
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        while (true) {
            cur->val = cur->next->val;
            if (cur->next->next == nullptr) {
                delete cur->next;
                cur->next = nullptr;
                break;
            }
            cur = cur->next;
        }
        cur = nullptr;
    }
};