#include <vector>
using namespace std;

/* TLE O(N^2)
 */
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i)
      dp[i + 1] = dp[i] + nums[i];
    int res = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (dp[j] - dp[i] + k >= (j - i) * nums[j - 1])
          res = max(res, j - i);
    return res;
  }
};
8
