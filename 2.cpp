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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* root = new ListNode(0);
        ListNode* p = root;
        int carryBit = 0;
        
        while(l1 != NULL || l2 != NULL) {

            int addNum1, addNum2;
            addNum1 = (l1 == NULL) ? 0 : l1->val;
            addNum2 = (l2 == NULL) ? 0 : l2->val;
            
            p->val = (addNum1 + addNum2 + carryBit)%10;
            carryBit = (addNum1 + addNum2 + carryBit)/10;
            
            
            l1 = (l1 == NULL) ? NULL: l1->next;
            l2 = (l2 == NULL) ? NULL: l2->next;
            
            if (l1 != NULL || l2 != NULL) {
                p->next = new ListNode(0);
                p = p->next;
            }

        }
        
        if (carryBit != 0) {
            p->next = new ListNode(1);
            p = p->next;
        }
        
        return root;
    }
};
