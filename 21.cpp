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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mergeList, *begin;
        bool flag;

        mergeList = begin = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) flag = false;
            else if (l2 == NULL) flag = true;
            else flag = l1->val < l2->val ? true : false;

            ListNode *node;
            if (flag) {
                node = new ListNode(l1->val);
                l1 = l1 -> next;
            }
            else {
                node = new ListNode(l2->val);
                l2 = l2 -> next;
            }

            if (mergeList == NULL) {
                mergeList = node;
                begin = mergeList;
            }
            else {
                mergeList->next = node;
                mergeList = mergeList->next;
            }
        }

        return begin;
    }
};
