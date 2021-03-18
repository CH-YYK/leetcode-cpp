#include <vector>

using namespace std;

/* dp[i][0] -> maxlength when arr[i-1] > arr[i]
 * dp[i][1] -> maxlength when arr[i-1] < arr[i]
 * dp[0][0] = 1, dp[0][1] = 1;

 * dp[i][0] = dp[i-1][1] + 1  when arr[i-1] > arr[i]
 * dp[i][1] = dp[i-1][0] + 1  when arr[i-1] < arr[i]
 */
class Solution {
public:
  int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
      if(arr[i-1] > arr[i])
        dp[i][0] = dp[i-1][1] + 1;
      else if(arr[i-1] < arr[i])
        dp[i][1] = dp[i-1][0] + 1;
    }

    int res = 1;
    for(int i = 0; i < n; ++i) {
      res = max(res, dp[i][0]);
      res = max(res, dp[i][1]);
    }
    return res;
  }
};
