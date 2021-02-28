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
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int a1, a2, carryOut = 0;
        ListNode *head = NULL;
        while (!s1.empty()||!s2.empty()) {
            a1 = popNumber(s1);
            a2 = popNumber(s2);
            ListNode *node = new ListNode((a1+a2+carryOut)%10);
            carryOut = (a1+a2+carryOut)/10;
            node->next = head;
            head = node;
        }
        if (carryOut == 1) {
            ListNode *node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }

    int popNumber(stack<int>& s) {
        if (s.empty()) {
            return 0;
        }
        else {
            int a = s.top();
            s.pop();
            return a;
        }
    }
};
