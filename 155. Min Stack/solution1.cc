#include <stack>
#include <map>
#include <limits>

using namespace std;

class MinStack {
private:
  stack<int> s;
  map<int,int> m;
  int _min;
public:
  /** initialize your data structure here. */
  MinStack() {
    _min = INT_MAX;
  }

  void push(int val) {
    s.push(val);
    m[val]++;
    _min = m.begin()->first;
  }

  void pop() {
    if(s.empty()) return;
    if(m[s.top()]-- == 1) m.erase(s.top());
    s.pop();
    _min = m.begin()->first;
  }

  int top() {
    if(!s.empty()) return s.top();
    else return 0;
  }

  int getMin() {
    return _min;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
