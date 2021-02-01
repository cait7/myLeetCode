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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *sorted = head, *unsorted=head->next;
        sorted->next = nullptr;
        while (unsorted) {
            ListNode *node = unsorted;
            unsorted = unsorted->next;
            sorted = singleNodeInsertion(sorted, node);
        }
        return sorted;
    }

    ListNode* singleNodeInsertion(ListNode *ptr, ListNode *node) {
        if (node->val < ptr->val) {
            node->next = ptr;
            return node;
        }
        ListNode *tmpNode = ptr, *lastNode;
        while(tmpNode) {
            if (tmpNode->val > node->val) {
                break;
            }
            lastNode = tmpNode;
            tmpNode = tmpNode->next;
        }
        lastNode->next = node;
        node->next = tmpNode;
        return ptr;
    }
};
