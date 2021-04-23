/* dp[j]: number of ways to combine numbers to target
 * dp[j] = sum(j- nums[k]) if nums[k] < j
 * dp[0] = 1;
 */
#include <vector>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i) {
      for(int& num : nums)
        if(i >= num)
          dp[i] += dp[i - num];
    }
    return dp[target];
  }
};
