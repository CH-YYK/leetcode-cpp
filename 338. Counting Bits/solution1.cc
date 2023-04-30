/* 5 = 2^2 + 0 * 2^1 + 1 -> 2 digits
 * 6 = 2^2 + 2^1 -> 2 digits
 * 7 = 2^2 + 2^1 + 1 -> 3 digits
 * 7 = 2^2 + 3 -> 1 + 2 = 3
 */

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> dp(num+1, 0);
    for(int i = 1; i <= num; ++i) {
      int n = i;
      while(n > 0) {
        // use pre-computed results
        if(dp[n] > 0) {
          dp[i] += dp[n];
          break;
        }

        // counting 1s
        int j = 1;
        while(j <= i) j *= 2;
        n -= (j / 2), ++dp[i];
      }
      dp[i] = m;
    }
    return dp;
  }
};
