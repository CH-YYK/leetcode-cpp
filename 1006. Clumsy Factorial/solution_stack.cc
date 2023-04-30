#include <vector>
using namespace std;

class Solution {
public:
  int clumsy(int N) {
    int buff = 0, res = N;
    vector<char> ops{'*', '/', '+', '-'};
    int i = 0, sign = 1;
    while(--N > 0) {
      i %= 4;
      if(ops[i] == '-') {
        buff = res;
        res = N;
        sign = -1;
      } else if (ops[i] == '+') {
        res = buff = buff + res * sign + N;
        buff = 0;
      } else if(ops[i] == '*')
        res *= N;
      else if(ops[i] == '/')
        res /= N;
      ++i;
    }
    return buff == 0 ? res : buff - res;
  }
};
