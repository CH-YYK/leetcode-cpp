class Solution {
public:
  /* dp(i) -> number of 3-element arithmetic slice ended by nums[i];
   * dp(i) = dp(i-1) + 1 if nums[i, i-1, i-2] is arithmetic else 0.
   * dp(0) = 0, dp(1) = 0
   */
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for(int i = 2; i < n; ++i)
      if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
        dp[i] = dp[i-1] + 1;
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
