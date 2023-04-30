class Solution {
public:
  /* Given an integer n, return least number of perfect square numbers
   * that sum to n (perfect square number: a * a)
   * [1, 2, 3, 4, 5] -> [1, 4, 9, 16, 25]
   *
   * There is only one least combination of perfect square numbers
   * sum to N
   *
   * dp(N) -> number of perfect square numbers
   * dp(N) = 1 if N is a perfect square number
   * dp(1) = 1
   * dp(13) = dp(4) + dp(9) = 2
   */
  int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i * i <= n; ++i)
      dp[i * i] = 1;
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j * j + i <= n; ++j)
        dp[i] = min(dp[i - j * j] + 1, dp[i]);
    return dp[n];
  }
};

