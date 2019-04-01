/*
    use two stacks
        stack1: keep track of values pushed to it
        stack2: keep track of min values currently
    
    when:
        push(x): stack1: receive x:
                 stack2: test if x is currently minimum:
                    True: receive x
        pop() : stack1: drop x
                stack2: test if x is currently minumum:
                    True: drop x
        min() : return top value of stack2
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class MinStack {
    stack<int> stack1;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stack1.push(x);
        if(mins.empty()) 
            mins.push(x);
        else if(x <= mins.top()) 
            mins.push(x);
    }
    
    void pop() {
        int x = stack1.top();
        stack1.pop();
        if(x == mins.top()) 
            mins.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */