class Solution {
public:
  /* Get the maximum amount of money
   * amt(i) -> maximum amount of money ended by the house i including i
   *    amt(i) = max(amt(i-1), amt(i-2) + nums[i-1])
   * amt(0) = 0, amt(1) = max(amt(0), nums[0])
   */
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> amt(n+1, 0);

    for(int i = 1; i <= n; ++i)
      if(i < 2)
        amt[i] = max(amt[i-1], nums[i-1]);
      else
        amt[i] = max(amt[i-1], amt[i-2] + nums[i-1]);
    return amt[n];
  }
};
