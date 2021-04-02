#include <vector>
#include <algorithm>
using namespace std;

/* dp[i][0] maximum product for any subarray ended by nums[i]
 * dp[i][1] minimum product for any subarray ended by nums[i]
 * We keep track of the state in this way (state for subarray ended by nums[i])
 *  Due to negative numbers, maximum could be created by negative * negative,
 *   so we keep the states for both max and min.
 */

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
    dp[0][0] = nums[0]; // max;
    dp[0][1] = nums[0]; // min;
    for (int i = 1; i < nums.size(); ++i) {
      dp[i][0] =
          max(nums[i], max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
      dp[i][1] =
          min(nums[i], min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
    }
    return (*max_element(dp.begin(), dp.end()))[0];
  }
};
