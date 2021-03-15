#include <string>
#include <vector>

using namespace std;

/* DP method
 * dp[i][j] -> lenth of LCS for text1[:i] and text2[:j]
 * if text1[i] == text2[j] -> dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1]) -> dp[i-1][j-1] + 1;
 * if text1[i] != text2[j] -> dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * dp[0][0] = 1 if text1[0] == text2[0] else 0;
 * dp[i][0] = dp[i-1][0] or (text1[i] == text2[0]);
 * dp[0][j] = dp[0][j-1] or (text2[j] == text1[0]);
 */
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = text1[0] == text2[0];

    for(int i = 1; i < m; ++i)
      dp[i][0] = dp[i-1][0] || (text1[i] == text2[0]);
    for(int j = 1; j < n; ++j)
      dp[0][j] = dp[0][j-1] || (text1[0] == text2[j]);

    for(int i = 1; i < m; ++i)
      for(int j = 1; j < n; ++j) {
        if(text1[i] == text2[j])
          dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    return dp[m-1][n-1];
  }
};
