#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string res;
    int m = num1.size(), n = num2.size();
    int prev = 0, curr, pos = 0; // pos marks the position where the digits aren't zeros
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        curr = (num1[i] - '0') * (num2[j] - '0') + prev;
        if (pos == res.size())
          res.push_back('0' + (curr % 10));
        else {
          curr += (res[pos] - '0');
          res[pos] = '0' + (curr % 10);
        }
        pos++;
        prev = curr / 10;
      }
      if (prev > 0)
        res.push_back('0' + prev);
      pos = m - i;
      prev = 0;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
