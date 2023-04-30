#include <stack>
#include <string>
#include <vector>

using namespace std;

/* Update to solution1.cc
 * Use a Number to store operands for '+' or '-'
 * Execute '*' or '/' immediately
 */

class Solution {
public:
  int calculate(string s) {
    int res = 0, n = s.size();
    int lastoperand;

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
          lastoperand += res;
          res = num;
          num = 0;
        } else if (ops == '-') {
          lastoperand += res;
          res = -1 * num;
          num = 0;
        }
        ops = s[i];
      }
    }
    res = operate(ops, res, num);
    return lastoperand += res;
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
