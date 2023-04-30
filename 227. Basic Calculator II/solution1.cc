#include <string>
#include <vector>
#include <stack>

using namespace std;

/* Use stack to store operands for '+' or '-'
 * Execute '*' or '/' immediately
 */
class Solution {
public:
  int calculate(string s) {
    int res = 0, n = s.size();
    stack<int> stk;

    int num = 0;
    char ops = '+';
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ')
        continue;
      if (isdigit(s[i]))
        num = 10 * num + (s[i] - '0');
      else {
        if (ops == '*' || ops == '/') {
          res = operate(ops, res, num);
          num = 0;
        } else if (ops == '+') {
          stk.push(res);
          res = num;
          num = 0;
        } else if (ops == '-') {
          stk.push(res);
          res = -1 * num;
          num = 0;
        }
        ops = s[i];
      }
    }
    res = operate(ops, res, num);
    while (!stk.empty())
      res += stk.top(), stk.pop();
    return res;
  }

private:
  int operate(char op, int lhs, int rhs) {
    if (op == '*')
      return lhs * rhs;
    if (op == '/')
      return lhs / rhs;
    if (op == '+')
      return lhs + rhs;
    if (op == '-')
      return lhs - rhs;
    else
      return 0;
  }
};
