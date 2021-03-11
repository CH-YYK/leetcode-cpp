#include <string>
#include <stack>

using namespace std;

/* use stack to save results prior to "()"
 *
 */
class Solution {
public:
  int calculate(string s) {
    stack<int> _s;
    int operand = 0;
    int res = 0;
    int sign = 1;

    for(int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if(isdigit(c))
        operand = 10 * operand + (c - '0');
      else if(c == '+') {
        res += sign * operand;
        sign = 1;
        operand = 0;
      } else if(c == '-') {
        res += sign * operand;
        sign = -1;
        operand = 0;
      } else if(c == '(') {
        _s.push(res);
        _s.push(sign);

        sign = 1;
        res = 0;
      } else if(c == ')') {
        res += sign * operand;
        res *= _s.top(), _s.pop();
        res += _s.top(), _s.pop();
        operand = 0;
      }
    }
    return res + sign * operand;
  }
};
