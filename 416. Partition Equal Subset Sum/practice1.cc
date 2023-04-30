#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/* Find a subset whose sum is half of the whole set
 * 0-1 knackpack as we use each number for only once and sum to Sum/2
 *
 * dp[i][j]: whether a subset from nums[:i] can sum to j
 * dp[i][j] = dp[i-1][j] if ith item isn't placed in subset
 * dp[i][j] = dp[i-1][j-nums[i]]
 * dp[i][0] = 1 as empty set created 0 sum.
 * dp[0][0] = 1
 * dp[0][j > 0] = 0
 */
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int Sum = accumulate(nums.begin(), nums.end(), 0);
    if(Sum % 2 > 0) return false;
    int target = Sum / 2;
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));

    for(int i = 0; i <= n; ++i)
      dp[i][0] = 1;

    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= target; ++j) {
        if(j >= nums[i-1])
          dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
      }
    }

    /* for(int i = 1; i <= n; ++i) {
         for(int j = 1; j <= target; ++j) {
         if(j >= nums[i-1])
           dp[j] = dp[j] || dp[j- nums[i-1]];  // rely on k where k < j, update j before k
         }
       }
     */
    return dp[n][target];
  }
};

