#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    /* res: the added left/right parentheses
     * right: amount of right parentheses required
     */
    int res = 0, right = 0;

    for(char c : s) {
      if(c == ')') {
        right--;
        if(right < 0)
          right+=2, res++; // add left balance
      } else {
        if(right % 2 > 0)
          right--, res++; // add one right to balance
        right += 2;
      }
    }
    return res + right;
  }
};
