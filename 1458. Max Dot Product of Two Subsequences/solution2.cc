#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    // dp[i][j] := max dot product that include nums1[i] and nums2[j]
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = nums1[0] * nums2[0];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int _curr = nums1[i] * nums2[j];
        if (i == 0 || j == 0) {
          // a1[i] or a2[j] must be used to compute dot product
          if (j >= 1)
            dp[i][j] = max(_curr, dp[i][j - 1]);
          if (i >= 1)
            dp[i][j] = max(_curr, dp[i - 1][j]);
        } else {
          // use current and drop previous
          dp[i][j] = _curr;
          // include current and previous
          dp[i][j] = max(dp[i][j], dp[i-1][j-1] + _curr);
          // drop current and use previousa
          dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
          
        }
      }
    return dp[m - 1][n - 1];
  }
};