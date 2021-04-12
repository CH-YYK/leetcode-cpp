#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    int sign = 1, res = 0, cache = 0, num = 0;
    s.push_back('+');
    char ops;
    for(char c : s) {
      if(c == ' ') continue;
      if(isdigit(c)) {
        num = num * 10 + (c - '0');
      } else {
        if(c == '+' || c == '-') {
          if (ops == '*') res *= num;
          else if (ops == '/') res /= num;
          else res += sign * num;
          res += cache;
          cache = 0;
          sign = c == '+' ? 1 : -1;
        } else if(c == '*' || c == '/') {
          if(ops == '*') res *= num;
          else if(ops == '/') res /= num;
          else {
            cache = res;
            res = sign * num;
          }
        }
        ops = c;
        num = 0;
      }
    }
    return res;
  }
};
