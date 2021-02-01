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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 找到中点
        ListNode *slowNode, *quickNode;
        slowNode = quickNode = head;
        while (quickNode) {
            quickNode = quickNode->next;
            if (quickNode) quickNode = quickNode->next;
            if (quickNode) slowNode = slowNode->next;
        }
        ListNode *l1, *l2;
        l1 = head;
        l2 = slowNode->next;
        slowNode->next = nullptr;
        // 划分
        l1 = sortList(l1);
        l2 = sortList(l2);
        // 归并
        return merge(l1, l2);
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *ans, *ptr;
        ans = ptr = nullptr;
        while (l1 || l2) {
            int v1 = l1 ? l1->val : INT_MAX, v2 = l2 ? l2->val : INT_MAX;
            ListNode *node = v1 > v2 ? l2 : l1;
            l1 = v1 > v2 ? l1 : l1->next;
            l2 = v1 > v2 ? l2->next: l2;
            if (!ans) {
                ans = ptr = node;
                continue;
            }
            ptr->next = node;
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        return ans;
    }
};
