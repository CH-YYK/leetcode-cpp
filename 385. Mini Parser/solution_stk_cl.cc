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
    stack<NestedInteger> stk({NestedInteger()});
    char prev;
    int i = 0;
    while(i < s.size()) {
      if (s[i] == '[') {
        stk.push(NestedInteger());
        i++;
      }
      if(s[i] == ']') {
        curr = stk.top();
        stk.pop();
        stk.top().add(curr);
        i++;
      }
      if(s[i] == ',') i++;
      else {
        int num = 0, sign = 1;
        if(s[i] == '-') sign = -1, i++;
        while(i < s.size() && isdigit(s[i]))
          num = num * 10 + (num - '0');
        stk.top().add(NestedInteger(num * sign));
      }
    }
    return stk.top().getList().front();
  }
};
