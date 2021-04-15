#include <vector>
using namespace std;

/* Manually control the state: rob 1st house?
 * 
 */
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // never rob house 1;
    for(int i = 1; i < n; ++i){
      dp[i][0] = dp[i-1][1] + nums[i];
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    res = max(dp[n-1][0], dp[n-1][1]);

    dp[0][0] = nums[0], dp[0][1] = 0;
    nums[1] = 0;
    nums[n-1] = 0;
    for(int i = 1; i < n; ++i){
      dp[i][0] = dp[i-1][1] + nums[i];
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    res = max(max(dp[n-1][0], dp[n-1][1]), res);
    return res;
  }
};
