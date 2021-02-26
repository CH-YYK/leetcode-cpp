class Solution {
public:
  /* nd(N) -> number of distinct ways to climb to Nth stair
   * nd(N) = nd(N-1) + nd(N-2)
   * nd(0) = 1, nd(1) = 1, nd(2) = 2
   */
  int climbStairs(int n) {
    vector<int> nums(n+1, 1);
    for(int i = 2; i <= n; ++i)
      nums[i] = nums[i-1] + nums[i-2];
    return nums[n];
  }
};
