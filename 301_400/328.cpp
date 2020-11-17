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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddList, *evenList, *evenNode, *ptr;
        if (head == nullptr) {
            return head;
        }
        oddList = head;
        if (head->next == nullptr) {
            return head;
        }
        evenList = evenNode = ptr = head->next;
        bool isEven = false;
        while(ptr->next!=nullptr) {
            if (!isEven) {
                oddList->next = ptr->next;
                oddList = oddList->next;
            }
            else {
                evenList->next = ptr->next;
                evenList = evenList->next;
            }
            isEven = !isEven;
            ptr = ptr->next;
        }
        oddList->next = evenNode;
        evenList->next = nullptr;
        return head;
    }
};
