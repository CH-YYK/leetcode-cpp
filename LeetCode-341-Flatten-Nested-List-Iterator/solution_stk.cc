#include <vector>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedInteger{
public:
  bool isInteger() const {
    
  }
  int getInteger() const;
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it)
      stk.push(*it);
  }

  int next() {
    int next_ = stk.top().getInteger();
    stk.pop();
    return next_;
  }

  bool hasNext() {
    while (!stk.empty() && !stk.top().isInteger()) {
      NestedInteger tmp = stk.top();  // copy/move is requried as stk.pop() will free the object
      stk.pop();
      const vector<NestedInteger>& nexts = tmp.getList();
      for (auto it = nexts.rbegin(); it != nexts.rend(); ++it)
        stk.push(*it);
    }
    if (stk.empty())
      return false;
    return true;
  }

private:
  stack<NestedInteger> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
