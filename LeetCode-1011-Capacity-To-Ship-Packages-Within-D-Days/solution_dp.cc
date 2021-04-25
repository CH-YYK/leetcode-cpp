#include <algorithm>
#include <vector>
using namespace std;
/* dp[i][d] : minimum of capacity to load weights[:i] in d days
 * dp[i][d] = min(max(dp[j][d-1], sum(nums[j : i]))) for j in [0, i]
 * dp[0][:] = 0
 */
class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    int n = weights.size();
    vector<int> dp(n, 1e9);
    vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; ++i)
      presum[i + 1] = presum[i] + weights[i];
    for (int i = 0; i < n; ++i)
      dp[i] = presum[i + 1];
    for (int d = 1; d < D; ++d)
      for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j)
          dp[i] = min(dp[i], max(dp[j], presum[i + 1] - presum[j + 1]));
      }
    return dp[n - 1];
  }
};
