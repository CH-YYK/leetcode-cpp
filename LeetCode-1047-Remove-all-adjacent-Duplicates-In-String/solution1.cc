/* Stack method
 */

class Solution {
public:
  string removeDuplicates(string S) {
    string stk;
    for(char c : S) {
      if(stk.empty()) stk.push_back(c);
      else if(stk.back() == c) stk.pop_back();
      else stk.push_back(c);
    }
    return stk;
  }
};
