#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    set<int> s;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j] = dp[i][j] + matrix[i][j];
    int row[n];
    int res = INT_MIN;
    for (int i = 0; i < m; ++i)
      for (int j = i; j < m; ++j) {
        s.insert(0);  // in case S_hi is good enough
        for (int c = 0; c < n; ++c) {
          row[c] = dp[j + 1][c] - dp[i][c];
          if (c > 0)
            row[c] += row[c - 1];
          auto it = s.lower_bound(row[c] - k);
          if (it != s.end() && row[c] - *it > res)
            res = row[c] - *it;
          s.insert(row[c]);
        }
        s.clear();
      }
    return res;
  }
};
