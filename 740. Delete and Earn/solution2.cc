#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(nums);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] - nums[j] > 1 || nums[j] - nums[i] > 1 ||
            nums[i] == nums[j])
          dp[i] = max(dp[j] + nums[i], dp[i]);
    return *max_element(dp.begin(), dp.end());
  }
};
