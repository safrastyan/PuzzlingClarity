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
    ListNode* mergeNodes(ListNode* head) {
        int cur = 0;
        std::vector<int> nums;
        while (head != nullptr) {
            int sum = 0;
            ListNode* temp = head->next;
            while (temp != nullptr && temp->val != 0) {
                sum += temp->val;
                temp = temp->next;
            }
            nums.push_back(sum);
            head = temp;
        }
        ListNode* ans = new ListNode(nums.front());
        ListNode* temp = ans;
        for (int i = 1; i < nums.size() - 1; ++i) {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }
        return ans;
    }
};