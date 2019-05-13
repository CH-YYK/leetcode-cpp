#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
    stack<int> push_;
    stack<int> pop_;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_.push(x);
        if(!pop_.empty())
            return;
        while(!push_.empty()) {
            pop_.push(push_.top());
            push_.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = pop_.top();
        pop_.pop();
        if(!pop_.empty())
            return tmp;
        while(!push_.empty()) {
            pop_.push(push_.top());
            push_.pop();
        }
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return pop_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pop_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */