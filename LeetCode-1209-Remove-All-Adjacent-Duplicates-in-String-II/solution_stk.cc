#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  string removeDuplicates(string s, int k) {
    int n = s.length();
    stack<pair<char, int>> stk;

    for(char c : s) {
      if(stk.empty()) stk.push({c, 1});
      else {
        while(!stk.empty() && stk.top().second == k)
          stk.pop();
        if(!stk.empty() && c == stk.top().first)
          stk.top().second++;
        else
          stk.push({c, 1});
      }
    }
    while(!stk.empty() && stk.top().second == k)
      stk.pop();

    string res;
    while (!stk.empty()) {
      res += string(stk.top().second, stk.top().first);
      stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
