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
    
    int pairSum(ListNode* head) {
        std::vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }    
        int b = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            b = std::max(b, nums[i] + nums[nums.size() - i -1]);
        }
        return b;
    }
};