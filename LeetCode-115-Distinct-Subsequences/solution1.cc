/* dp[i][j] => # of ways that s[:j] generate t[:i]
 * when s[j-1] == t[i-1]
 *   case1: s[:j-1] => t[:i-1], let s[j-1] => t[i-1]
 *   case2: s[:j-1] => t[:i], disregard s[j-1]
 * while s[j-1] != t[i-1]:
 *   case: s[:j-1] => t[:i], disregard s[j-1]
 *
 * Initialize:
 *  dp[0][:] = 1
 *  dp[1:][:] = 0
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = t.size(), n = s.size();
    // prepare DP
    long dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j)
        if (i == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (s[j - 1] == t[i - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
    return dp[m][n];
  }
};
