#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    s.push_back('+');
    int res = 0, lastnum = 0, num = 0;
    char sign = '+';

    for (char c : s) {
      if (c == ' ')
        continue;
      else if (isdigit(c))
        num = num * 10 + (c - '0');
      else {
        if (sign == '+' || sign == '-') {
          res += lastnum;
          lastnum = sign == '+' ? num : -num;
        } else if (sign == '*')
          lastnum *= num;
        else if (sign == '/')
          lastnum /= num;

        sign = c;
        num = 0;
      }
    }
    return res + lastnum;
  }
};
