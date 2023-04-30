#include <vector>

using namespace std;

/* dp[2][height.size()]
 * dp[0][i] : the height of left bar of water at index i
 * dp[1][i] : the height of right bar of water at index i
 *
 *
 */
class Solution {
public:
  int trap(vector<int> &height) {
    if(height.empty()) return 0;
    int n = height.size();
    int dp[2][n];
    dp[0][0] = height[0];
    dp[1][n-1] = height[n-1];

    for(int i = 1; i < n; ++i)
      dp[0][i] = max(dp[0][i-1], height[i]);

    for(int j = n-2; j >= 0; --j)
      dp[1][j] = max(dp[1][j+1], height[j]);

    int res = 0;
    for(int i = 1; i < n-1; ++i) {
      int h = min(dp[0][i], dp[1][i]);
      res += (h - height[i]);
    }
    return res;
  }
};
