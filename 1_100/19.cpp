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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == NULL) {
            return head;
        }

        ListNode *ptr1, *ptr2;
        
        ptr1 = ptr2 = head;
        n = n + 1;

        while (true) {
            if (!n) {
                ptr1 = ptr1->next;
            }

            ptr2 = ptr2->next;
            n = n > 0 ? n-1 : 0;

            if (ptr2 == NULL) {
                ListNode *delNode;

                if (n > 0) {
                    delNode = head;
                    head = delNode->next;
                }
                else {
                    delNode = ptr1->next;
                    ptr1->next = delNode->next;
                }
                
                delete delNode;
                break;
            }
        }

        return head;
    }
};
