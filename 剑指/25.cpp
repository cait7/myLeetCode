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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans, *ptr, *node;
        ans = NULL;
        while (l1 || l2) {
            if (!l1) {
                node = l2;
                l2 = l2->next;
            }
            else if (!l2) {
                node = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val){
                node = l2;
                l2 = l2->next;
            }
            else {
                node = l1;
                l1 = l1->next;
            }
            if (!ans) {
                ans = ptr = node;
            }
            else {
                ptr->next = node;
                ptr = ptr->next;
            }

        }
        return ans;
    }
};
