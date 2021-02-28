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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode *ptr = head, *nextHead = NULL, *ans = NULL, *tail = NULL;
        while (ptr) {
            nextHead = ptr;
            int count = 0;
            for (int i=0; i<k && nextHead; i++) {
                nextHead = nextHead->next;
                count++;
            }
            // reverse k listNodes and return head pointer
            ptr = count == k ? reverseKNodes(ptr, k) : ptr;
            if (!ans) {
                ans = tail = ptr;
                while(tail->next != NULL) {
                    tail = tail->next;
                }
            }
            else {
                tail->next = ptr;
                while(tail->next != NULL) {
                    tail = tail->next;
                }
            }
            ptr = nextHead;
        }
        return ans;
    }

    ListNode* reverseKNodes(ListNode *ptr, int k) {
        if (ptr == NULL) {
            return NULL;
        }
        ListNode *tail = NULL, *nPtr = ptr->next, *tPtr;
        while (k--) {
            ptr->next = tail;
            tail = ptr;
            ptr = nPtr;
            if (ptr == NULL) {
                break;
            }
            nPtr = ptr->next;
        }
        return tail;
    }
};
