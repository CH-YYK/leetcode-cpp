#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int getMaximumConsecutive(vector<int> &coins) {
    int n = coins.size();
    int summ = accumulate(coins.begin(), coins.end(), 0);
    vector<vector<int>> dp(n+1, vector<int>(summ+1, 0));
    for(int i = 0; i <= n; ++i) dp[i][0] = 1;
    for(int i = 0; i < n; ++i) {
      for(int j = coins[i-1]; j <= summ; ++j) {
        dp[i][j] = j == coins[i-1] || dp[i-1][j-coins[i-1]];
      }
    }
    for(int j = 1; j <= summ; ++j) {
      dp[n-1][j] = (j == coins[n-1]) || dp[n-2][j-coins[n-1]];
      if(!dp[n-1][j]) return j;
    }
    return summ+1;
  }
};
