#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int getMaximumConsecutive(vector<int> &coins) {
    int n = coins.size();
    // dp[i]: rightmost consecutive number with coins[:i], [0,i-1]
    vector<int> dp(n + 1, 0);
    sort(coins.begin(), coins.end());
    for(int i = 1; i <= n; ++i) {
      int l = coins[i-1], r = dp[i-1] + coins[i-1];
      if(l <= dp[i-1]) dp[i] = r;
      else return l;
    }
    return dp[n];
  }
};
