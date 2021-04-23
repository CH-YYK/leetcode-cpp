#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    memo = vector<int>(s.size(), -1);
    return ndecode(s, 0);
  }

private:
  vector<int> memo;
  int ndecode(string &s, int i) {
    if (i >= s.size())
      return 1;
    if (memo[i] >= 0)
      return memo[i];
    int res = 0;
    int num = s[i] - '0';
    if (num == 0)
      return 0;

    res += ndecode(s, i + 1);
    if (i + 1 == s.size())
      return res;
    num = num * 10 + (s[i + 1] - '0');
    if (num > 26)
      return memo[i] = res;
    res += ndecode(s, i + 2);
    return memo[i] = res;
  }
};
