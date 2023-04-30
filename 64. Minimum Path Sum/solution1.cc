class Solution {
public:
  /* topleft -> bottomright, minimize the sum of all numbers
   * dp(m, n) maximum sum of numbers in grid[i < m][j < n]
   *  - dp(m, n) = min(dp(m-1, n), dp(m, n-1)) + grid[m][n];
   *  - dp(0, 0) = grid[0][0]
   */
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if(i == 0 && j == 0)
          dp[i][j] = grid[i][j];
        else if(i == 0 && j > 0)
          dp[i][j] = dp[i][j-1] + grid[i][j];
        else if(j == 0 && i > 0)
          dp[i][j] = dp[i-1][j] + grid[i][j];
        else
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    return dp[m-1][n-1];
  }
};
