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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *latter, *former;
        latter = former = head;
        while (k--) {
            latter = latter->next;
        }
        while (latter) {
            latter = latter->next;
            former = former->next;
        }
        return former;
    }
};
