#include <vector>
using namespace std;


/* Range based DP
 * dp[i][j][K]: minimum cost to merge stones[i:j+1] into K piles
 * dp[i][j][1]: minimum cost to merge stones[i:j+1] into 1 pile
 *
 * dp[i][j][k] = min(dp[i][m][1] + dp[m+1][j][k-1], for all m in [i,j+1]);
 * dp[i][j][1] = dp[i][j][K] + sum(stones[i:j+1])
 *
 * init: dp[i][i+K-1][1] = sum(stones[i:i+K]), i.e. dp[i][j][1] = INF elsewhere
 */
class Solution {
public:
  int mergeStones(vector<int> &stones, int K) {
    const int n = stones.size();
    if ((n - 1) % (K - 1) != 0)
      return -1;

    vector<int> sums(n + 1, 0);
    for (int i = 0; i < n;
         ++i) // prefix sum: sums[j] - sums[i] = sum(stones[i:j])
      sums[i + 1] = sums[i] + stones[i];

    const int kInf = 1000000000;
    // dp[i][j][k] := min cost to merge subarray [i~j] into k piles
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(K + 1, kInf)));
    for (int i = 0; i < n; ++i)
      dp[i][i][1] = 0;

    for (int l = 2; l <= n; ++l)
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;
        for (int k = 2; k <= K; ++k)
          for (int m = i; m < j; m += K - 1) // m+1 <= j
            dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
        if ((l - 1) % (K - 1) == 0)
          dp[i][j][1] = dp[i][j][K] + sums[j + 1] - sums[i];
      }
    return dp[0][n - 1][1];
  }
};
