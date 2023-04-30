#include <string>
#include <stack>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedInteger {
public:
  NestedInteger();
  NestedInteger(int value);
  bool isInteger() const;
  int getInteger() const;
  void setInteger(int value);
  void add(const NestedInteger& ni);
  const vector<NestedInteger>& getList() const;
};

class Solution {
public:
  NestedInteger deserialize(string s) {
    int num = 0, sign = 1;
    NestedInteger curr;
    stack<NestedInteger> stk;
    char prev;
    for (char c : s) {
      if (isdigit(c))
        num = num * 10 + (c - '0');
      else {
        // create a NestedInteger if a number is parsed
        if (isdigit(prev))
          curr.setInteger(num * sign), sign = 1;

        // set sign to -1 to represent negative
        if (c == '-')
          sign = -1;
        // Literatly added the current NestedInteger to stack.
        else if (c == ',') {
          stk.top().add(curr);
          curr = NestedInteger();
        }
        // Pushed the current NestedInteger to stack then adding
        else if (c == '[') {
          stk.push(curr);
          curr = NestedInteger();
        }
        // Pop from the stack, added current NestedInteger to stack if required. [343, [], 343]
        else if (c == ']') {
          if (prev != '[')
            stk.top().add(curr);
          curr = stk.top();
          stk.pop();
        }
        num = 0;
      }
      prev = c;
    }
    if (isdigit(prev))
      curr.setInteger(num * sign);
    return curr;
  }
};
