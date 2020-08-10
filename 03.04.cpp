// 1 2 3 4 5 6
// 5 4 3 2 1

// 1 2 3 4 5 6

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        invert = 1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!invert) {
            invertStack();
        }

        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (invert) {
            invertStack();
        }

        int ele = stack2.top();
        stack2.pop();

        return ele;
    }
    
    /** Get the front element. */
    int peek() {
        if (invert) {
            invertStack();
        }

        return stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return invert ? stack1.size() == 0 : stack2.size() == 0;
    }

    void invertStack() {
        if (invert) {
            int ele;
            while(!stack1.empty()) {
                ele = stack1.top();
                stack1.pop();
                stack2.push(ele);
            }
        }
        else {
            int ele;
            while(!stack2.empty()) {
                ele = stack2.top();
                stack2.pop();
                stack1.push(ele);
            }
        }

        invert = !invert;
    }

private:
    bool invert;
    stack<int> stack1, stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
