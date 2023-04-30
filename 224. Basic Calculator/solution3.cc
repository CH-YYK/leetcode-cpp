/* Spread the parenthesis and run pure computation
 */
#include <stack>
#include <string>

using namespace std;

/* use stack to save results prior to "()"
 *  > + (3 - 1 + 2) -> 3 - 1 + 2
 *  > the stack save the sign prior the current parenthesis
 *  > current step of calculation is res + sign * operator * num
 *  > everytime calculation in parenthesis is closed pop the sign stack.
 */
class Solution {
public:
  int calculate(string s) {
    stack<int> signs;
    signs.push(1);  // assume the expression is wrapped in parenthesis
    int ops = 1, num = 0;
    int res = 0;
    for(char c : s) {
      if(c == ' ') continue;
      if (isdigit(c)) {
        num = 10 * num + (c - '0');
        continue;
      }
      res += ops * num;
      num = 0;
      // define the ops for next number
      if (c == '+')
        ops = signs.top();
      else if (c == '-')
        ops = -signs.top();
      else if (c == '(') // save the sign to be applied in parenthesis
        signs.push(ops);
      else if (c == ')')
        signs.pop();
    }
    return res + ops * num; // a number is generated at the end of loop
  }
};
