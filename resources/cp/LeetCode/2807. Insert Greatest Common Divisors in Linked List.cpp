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

 int gcd(int a, int b)
{
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res = new ListNode(head->val);
        ListNode* current_head = res;
        while (head->next != nullptr) {
            ListNode* cur = new ListNode(gcd(head->val, head->next->val));
            current_head->next = cur;
            current_head = cur;
            current_head->next = new ListNode(head->next->val);
            current_head = current_head->next;
            head = head->next;
        }
        return res;
    }
};