class Solution {
public:
  /* Find the largest square containing only 1's
   * dp(m, n) -> width of minimal square cornered by matrix[m][n]
   *   dp(m, n) = min(dp(m-1, n), dp(m, n-1), dp(m-1, n-1)) + 1
   *
   *   dp(m, n) = 0 if matrix[m][n] == 0
   *   dp(0, 0) = 1 if matrix[0][0] == 1
   *
   */
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 1));
    int res = 0;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j) {
        if(matrix[i][j] == '0')
          dp[i][j] = 0;
        else if(i > 0 && j > 0)
          dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
        res = max(res, dp[i][j]);
      }
    return res * res;
  }
};
