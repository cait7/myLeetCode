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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return mergeLists(lists, 0, lists.size()-1);
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {

        if (start > end) {
            return NULL;
        }

        if (start == end) {
            return lists[start];
        }

        ListNode *list1, *list2;
        int mid;

        mid = (start + end) / 2;
        list1 = mergeLists(lists, start, mid);
        list2 = mergeLists(lists, mid+1, end);

        return merge(list1, list2);
    }

    ListNode* merge(ListNode *list1, ListNode *list2) {

        ListNode *ptr, *head;
        ptr = head = NULL;

        while(list1 != NULL || list2 != NULL) {
            ListNode *node;

            if (list1 == NULL) {
                node = new ListNode (list2->val);
                list2 = list2->next;
            }
            else if (list2 == NULL || list1->val < list2->val) {
                node = new ListNode (list1->val);
                list1 = list1->next;
            }
            else {
                node = new ListNode (list2->val);
                list2 = list2->next;
            }

            if (ptr == NULL) {
                ptr = head = node;
            }
            else {
                ptr->next = node;
                ptr = ptr->next;
            }
        }

        return head;
    }
};
