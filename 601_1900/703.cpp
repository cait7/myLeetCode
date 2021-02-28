struct Listnode {
    Listnode *next;
    int val;
    Listnode(int val) {
        next = NULL;
        this->val = val;
    }
};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k-1;
        this->head = NULL;
        for (auto ele: nums) {
            insert(ele);
        }
    }
    
    int add(int val) {
        insert(val);
        Listnode *ptr = head;
        int count = k;
        while(count--) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void insert(int val) {
        Listnode *node = new Listnode (val);
        if (head == NULL || head->val < val) {
            node->next = head;
            head = node;
        }
        else {
            Listnode *ptr = head, *nPtr = head->next;
            while (nPtr != NULL && nPtr->val > val) {
                ptr = nPtr;
                nPtr = nPtr->next;
            }
            ptr->next = node;
            node->next = nPtr;
        }
    }

private:
    int k;
    Listnode *head;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
