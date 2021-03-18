#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    int len = 0, n = s.size();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    for (int j = 0; j < n; ++j)
      if (ispalindrome(s, 0, j))
        len = max(len, j + 1);
    string res;
    for (int i = n - 1; i >= len; --i)
      res += s[i];
    return res + s;
  }

private:
  vector<vector<int>> memo;
  bool ispalindrome(string &s, int i, int j) {
    if (i > j)
      return true;
    if (i == j)
      return memo[i][j] = true;
    if(memo[i][j] >= 0) return memo[i][j];

    if (s[i] == s[j])
      return memo[i][j] = ispalindrome(s, i + 1, j - 1);
    return memo[i][j] = false;
  }
};
