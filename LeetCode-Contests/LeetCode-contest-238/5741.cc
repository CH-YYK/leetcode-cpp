#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &restrictions) {
    vector<int> dp(n, -1);
    for (auto &p : restrictions)
      dp[p[0] - 1] = p[1];
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
      if (dp[i] != -1)
        dp[i] = min(dp[i - 1] + 1, dp[i]);
      else
        dp[i] = dp[i - 1] + 1;
    }
    int res = 0;
    for (int i = n - 1; i >= 1; --i) {
      if (i < n - 1 && dp[i + 1] + 1 < dp[i])
        dp[i] = dp[i + 1] + 1;
      if (dp[i] > res)
        res = dp[i];
    }
    return res;
  }
};
