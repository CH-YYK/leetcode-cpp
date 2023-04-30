class Solution {
public:
  int findLength(vector<int> &A, vector<int> &B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      dp[i][0] = A[i] == B[0] ? 1 : 0;
    for (int j = 0; j < n; ++j)
      dp[0][j] = A[0] == B[j] ? 1 : 0;

    int res = 0;
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j) {
        if (A[i] == B[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        res = max(res, dp[i][j]);
      }
    return res;
  }
};
