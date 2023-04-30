
/* Keep track of state i and j in dp[i][j]
 * dp[i][j] minimum difficulty of schedule for jobs[:i] and before during j days

 * Case: job[i] can only be placed on day[j]
 * dp[i][j] = max(
 * dp[i-1][j-1] + job[i]
 * dp[i-2][j-1] + max(job[i], job[i-1])
 * dp[i-3][j-1] + max(job[i], job[i-1], job[i-3])
 * ...
 * dp[k-1][j-1] + max(job[i], job[i-1], job[i-3],..jon[j] job)
 * )
 * dp[i][j] = INT_MAX if j > i;
 */
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d)
      return -1;
    vector<vector<int>> dp(n, vector<int>(d, INT_MAX));

    dp[0][0] = jobDifficulty[0];
    for (int i = 1; i < n; ++i)
      dp[i][0] = max(dp[i - 1][0], jobDifficulty[i]);

    for (int i = 1; i < n; ++i)
      for (int j = 1; j < min(i + 1, d); ++j) {
        int currmax = 0;
        for (int k = i; k >= j; --k) {
          currmax = max(currmax, jobDifficulty[k]);
          dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + currmax);
        }
      }
    return dp[n - 1][d - 1];
  }
};
