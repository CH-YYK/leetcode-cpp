
#include <string>
#include <cstring>
#include <vector>
using namespace std;

/* dp[i][j] -> length of longest common subsequence for text1[:i] and text2[:j]
 * if text1[i-1] == text2[j-1]: dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j],
 dp[i][j-1])
 * if text1[i-1] != text2[j-1]: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 * if text1[0] == text2[0]: dp[0][0] = 1 else dp[0][0] = 0;

 * dp[1][j] = max(dp[0][j-1], text1[0] == text2[j-1])
 * dp[i][1] = max(dp[i-1][0], text1[i-1] == text2[0])
 */
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, (m + 1) * (n + 1));
    // text1[i-1]
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
};
