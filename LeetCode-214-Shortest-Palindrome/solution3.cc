#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    int len = 0;
    n = s.size();
    memo = unordered_map<int, int>();
    for (int j = 0; j < n; ++j)
      if (ispalindrome(s, 0, j))
        len = max(len, j + 1);
    string res;
    for (int i = n - 1; i >= len; --i)
      res += s[i];
    return res + s;
  }

private:
  unordered_map<int, int> memo;
  int n;
  bool ispalindrome(string &s, int i, int j) {
    if (i > j)
      return true;
    if (i == j)
      return memo[i * n + j] = true;
    if (memo.count(i * n + j))
      return memo[i * n + j];

    if (s[i] == s[j])
      return memo[i * n + j] = ispalindrome(s, i + 1, j - 1);
    return memo[i * n + j]= false;
  }
};
