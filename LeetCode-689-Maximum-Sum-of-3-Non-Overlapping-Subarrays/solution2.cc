#include <vector>
#include <algorithm>
using namespace std;

/* Sliding window get k-num sum for each index
 * Search for best combination for the window of sums
 * memoization could be applied to boost search

 * find cumulative sum with sliding window
 * sums[i] = sum(nums[i], nums[i+1],.. nums[i+k-1])

 * Find maximum summation in sums by 01Knapack with (W = 3, v_i = 1, w_i = 1, Sum as V)
 *   dp[i][j]:= maximum sum we can get from sums[:i] inclusive in the set of size j
 *   dp[i][j] = max(dp[i-1][j], dp[i-k][j-1] + sums[i])  keep sums[i] and increase set size by 1 or not
 *
 *   Initialize dp[i][j] = 0
 *     dp[i][0] = max(dp[i-1][0], sums[i]);
 */
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    // find cumulative sums by sliding window
    vector<int> sums(n - k + 1, 0); // n-(k-1)
    int l = 0, sum = 0;
    for (int r = 0; r < n; ++r) {
      sum += nums[r];
      if (r - l + 1 == k) {
        sums[l] = sum;
        sum -= nums[l++];
      }
    }
    // find maximum by dp (01 knapack with W = 3, w = 1, V as sums)
    vector<vector<int>> dp(sums.size() + 1, vector<int>(3, 0));
    dp[1][0] = sums[0];
    for(int i = 1; i <= sums.size(); ++i)  // keep maximum number when  j == 0
      dp[i][0] = max(sums[i-1], dp[i-1][0]);
    for (int i = 1; i <= sums.size(); ++i) {
      for (int j = 1; j < min(3, i); ++j) {
        if(i >= k)
          dp[i][j] = max(dp[i-k][j-1] + sums[i-1], dp[i-1][j]);
      }
    }
    // find results by substracting sums[i] from maximum iteratively
    vector<int> res;
    int maxsum = dp[sums.size()][2];
    for(int j = 2; j>=0; --j)
      for(int i = 1; i<=sums.size(); ++i)
        if(dp[i][j] == maxsum) {
          res.push_back(i-1);
          maxsum -= sums[i-1];
          break;
        }
    reverse(res.begin(), res.end());
    return res;
  }
};
