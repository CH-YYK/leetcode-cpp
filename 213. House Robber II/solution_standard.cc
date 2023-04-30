#include <vector>
using namespace std;

/* Manually control the state: rob 1st house?
 * dp[i] = max(dp[i-2] + nums[i], dp[i-1])
 * rob(0, n-2) or rob(1, n-1);
 *
 * A Circle means that we cannot rob both house[0] and house[n-1]
 * res = max(robbing nums[0:n-2], robbing nums[1:n-1]) (right inclusive)
 *
 * if(rob n - 2), dp[n] = dp[n-2] + nums[n] = dp[n-1]+ nums[n];
 */
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
  }

private:
  int robRange(vector<int> &nums, int start, int end) {
    // first: dp[i-2], second: dp[i-1] or current
    int first = nums[start], second = max(nums[start], nums[start+1]);
    for(int i = start + 2; i <= end; ++i) {
      int tmp = second;
      second = max(first + nums[i], second);
      first = tmp;
    }
    return second;
  }
};
