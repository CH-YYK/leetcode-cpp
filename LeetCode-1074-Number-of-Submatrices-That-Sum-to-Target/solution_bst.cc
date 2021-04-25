#include <vector>
#include <unordered_map>
using namespace std;

/* Build prefix sum of matrix
 * Try each segment of columns (i,j) and use column sums matrix[i:j+1][c]
 * Reduce the problem to 1-D: find # of subarrays whose sum are equal to target
 *
 * O(MN^2)
 */
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j] = dp[i][j] + matrix[i][j];
    int res = 0, row[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < m; ++i)
      for (int j = i + 1; j <= m; ++j) {
        mp[0] = 1;
        for (int c = 0; c < n; ++c) {
          row[c] = dp[j][c] - dp[i][c];
          if (c > 0)
            row[c] += row[c - 1];
          if (mp.count(row[c] - target))
            res += mp[row[c] - target];
          mp[row[c]]++;
        }
        mp.clear();
      }
    return res;
  }
};
