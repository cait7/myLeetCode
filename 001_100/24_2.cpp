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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr, *last, *before, *ans;
        curr = head;
        ans = before = NULL;
        while (curr) {
            last = curr->next;
            if (!last) {
                break;
            }
            curr->next = last->next;
            last->next = curr;
            if (before) {
                before->next = last;
            }
            // next pair
            before = curr;
            curr = curr->next;
            if (!ans) {
                ans = last;
            }
        }
        return ans == NULL ? head : ans;
    }
};
