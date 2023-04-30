#include <vector>
using namespace std;

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j + 1] =
            dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
    int res = INT_MIN, diff;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        for (int i2 = i + 1; i2 < m + 1; ++i2)
          for (int j2 = j + 1; j2 < n + 1; ++j2) {
            diff = dp[i2][j2] - (dp[i][j2] + dp[i2][j] - dp[i][j]);
            if (diff <= k && diff > res)
              res = diff; // save an operation of max, brute force get accepted
          }
      }
    return res;
  }
};
