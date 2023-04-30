/* dp[i][j] = dp[i+1][j-1] & s[i] == s[j]
 * Base case:
 *   dp[i][i] = 1
 *   dp[i][i+1] = s[i] == s[j]
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case 1: one-character substring
    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;
    // base case 2: two-character substring
    for (int i = 0; i < n - 1; ++i)
      dp[i][i + 1] = s[i] == s[i + 1];

    // all cases for len-character substring
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        res += dp[i][j];
    return res;
  }
};
