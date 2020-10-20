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
    ListNode* swapPairs(ListNode* head) {

        ListNode *ptr1, *ptr2, *beyond, *below;

        below = NULL;
        ptr1 = head;
        ptr2 = ptr1 == NULL ? NULL : ptr1->next;

        while (ptr1 != NULL && ptr2 != NULL) {

            beyond = ptr2->next;

            if (below == NULL) {
                head = ptr2;
            }
            else {
                below->next = ptr2;
            }

            ptr2->next = ptr1;
            ptr1->next = beyond;

            below = ptr1;
            ptr1 = beyond;
            ptr2 = ptr1 == NULL ? NULL : ptr1->next;
        }

        return head;
    }
};
