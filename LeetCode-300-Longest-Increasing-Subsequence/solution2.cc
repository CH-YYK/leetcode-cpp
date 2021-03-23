#include <vector>

using namespace std;
/* dp[i]: The minimum number ended by a LIS of size i+1 (patience sorting)
 * 1. search for the right position of num in dp, dp[j] > num
 * 2. replace dp[j] by num
 * 3. length of dp stand for maximum length of LIS
 */
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;

    for(int num : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), num);
      if(it == dp.end())
        dp.push_back(num);
      else
        *it = num;
    }
    return dp.size();
  }
};
