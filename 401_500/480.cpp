class Solution {
public:
    struct ListNode {
        ListNode *next;
        int val;
        ListNode(int v) {
            next = NULL;
            val = v;
        }
    };

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ListNode *ptr;
        ptr = NULL;
        for (int i=0; i<k; i++) {
            ptr = insertNode(ptr, nums[i]);
        }
        vector<double> ans;
        ans.push_back( getMedian(ptr, k) );
        for (int i=k; i<nums.size(); i++) {
            ptr = removeFromList(ptr, nums[i-k]);
            ptr = insertNode(ptr, nums[i]);
            ans.push_back( getMedian(ptr, k) );
        }
        return ans;
    }

    ListNode* insertNode(ListNode *ptr, int val) {
        ListNode *node = new ListNode(val), *head = ptr, *previous = ptr;
        node->next = NULL;
        if (head == NULL || head->val >= val) {
            node->next = head;
            return node;
        }
        while (ptr != NULL &&  ptr->val < val) {
            previous = ptr;
            ptr = ptr->next;
        }
        previous->next = node;
        node->next = ptr;
        return head;
    }

    ListNode* removeFromList(ListNode *ptr, int val) {
        ListNode *head = ptr, *previous = ptr;
        if (head->val == val) {
            return head->next;
        }
        while (ptr != NULL && ptr->val != val) {
            previous = ptr;
            ptr = ptr->next;
        }
        previous->next = ptr->next;
        return head;
    }

    double getMedian(ListNode *ptr, int k) {
        if (k == 1) {
            return ptr->val;
        }
        int count = k/2 - 1;
        while (count) {
            ptr = ptr->next;
            count--;
        }
        if (k%2 == 0) {
            return (ptr->val*1.0 + ptr->next->val*1.0)/2;
        }
        else {
            return ptr->next->val;
        }
    }

    void display(ListNode *ptr) {
        while (ptr != NULL) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};
