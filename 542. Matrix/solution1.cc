#include <vector>

using namespace std;

class Solution {
public:
  /* Find the distance of nearest 0 for each cell.
   *   - Breadth first search -> BFS + memo -> DP
   * -1. Anlyze nearest 0s left to or above the current cell
   * -2. Anlyze nearest 0s right to or above the current cell
   *   >1: dp(m, n) = min(dp(m-1, n), dp(m, n-1)) + 1
   *   >2: dp(m, n) = min(min(dp(m+1, n), dp(m, n+1)) + 1, dp(m, n))
   *
   *   dp(m, n) = 0 if matrix[m][n] = 0
   *   >1. dp(0, 0) = INT_MAX;
   *   >2. dp(M-1 ,N-1) = INT_MAX;
   */
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // INT_MAX-1 avoid overflow
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX-1));

    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if(matrix[i][j] == 0)
          dp[i][j] = 0;
        else {
          if(j > 0)
            dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
          if(i > 0)
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
        }
    for(int i = m-1; i >= 0; --i)
      for(int j = n-1; j >= 0; --j) {
        if(i < m-1)
          dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
        if(j < n-1)
          dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
      }
    return dp;
  }
};
