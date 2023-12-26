#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
  /* Given a non-empty array nums containing positive numbers only.
   * Find if the array canbe partitioned into two subsets whose sums are equal.
   *
   * -> check whether there is a subset sum to sum(nums)/ 2;
   *
   * dp[i][target] -> is there a subset of nums[0:i] sum to target
   *
   * dp[i][target] = dp[i-1][target] || dp[i-1][target - nums[i-1]] (1 for each)
   * dp[i][0] = true;
   */
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0) return false;

    int target = sum / 2;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
    dp[0][0] = true;
    for(int i = 0; i <= n; ++i)
      dp[i][0] = true;

    for(int i = 1; i <= n; ++i) {
      for(int j = 0; j <= target; ++j)
        if(j == 0) dp[i][j] = true;
        else if(j >= nums[i-1])
          dp[i][j] = dp[i - 1][j] || dp[i-1][j - nums[i-1]];
    }
    return dp[n][target];
  }
};
