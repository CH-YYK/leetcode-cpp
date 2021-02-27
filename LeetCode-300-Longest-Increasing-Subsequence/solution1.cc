class Solution {
public:
  /* Given an integer array nums, return the length of LIS
   * dp(i) -> length of LIS in nums[0:i], right exclusively.
   *   dp(i) = max([dp(j) for j in [0, i-1] if nums[i-1] >= nums[j-1]]) + 1
   *   dp(0) = 0;
   */
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1, 1);
    dp[0] = 0;
    int res = 0;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j < i; ++j)
        if(i > 0 && j > 0)
          if(nums[i-1] > nums[j-1])
            dp[i] = max(dp[j] + 1, dp[i]);
      res = max(res, dp[i]);
    }
    return res;
  }
};
