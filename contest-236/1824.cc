#include <vector>
using namespace std;

class Solution {
public:
  int minSideJumps(vector<int> &obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(n, vector<int>(3, INT_MAX - 1));
    for (int i = 0; i < n; ++i)
      if (obstacles[i] == 0)
        continue;
      else
        dp[i][obstacles[i] - 1] = INT_MAX - 1;

    dp[0][1] = 0;
    dp[0][0] = obstacles[0] == 1 ? dp[0][0] : 1;
    dp[0][2] = obstacles[0] == 3 ? dp[0][2] : 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 3; ++j)
        if (obstacles[i] - 1 != j) dp[i][j] = dp[i - 1][j];
      if (obstacles[i] != 1)
        dp[i][0] = min(dp[i][0], min(dp[i][1], dp[i][2]) + 1);
      if (obstacles[i] != 3)
        dp[i][2] = min(dp[i][2], min(dp[i][1], dp[i][0]) + 1);
      if (obstacles[i] != 2)
        dp[i][1] = min(dp[i][1], min(dp[i][0], dp[i][2]) + 1);
    }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};
