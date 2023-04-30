#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    string res;
    int n = s.size();
    vector<int> rm(n, 0);
    stack<int> stk;

    for(int i = 0; i < n; ++i) {
      if(s[i] == ')') {
        if(stk.empty()) rm[i] = 1;
        else stk.pop();
      }else if(s[i] == '(')
        stk.push(i);
    }
    while(!stk.empty())
      rm[stk.top()] = 1, stk.pop();
    for(int i = 0; i < n; ++i)
      if(rm[i] == 0)
        res += s[i];
    return res;
  }
};
