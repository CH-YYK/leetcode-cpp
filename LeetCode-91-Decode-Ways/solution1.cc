#include <string>

using namespace std;

class Solution {
public:
  /* Given a integer, try to decode it by characters A~Z
   * dp(i) -> number of decode ways to decode s[0:i] (ended by i-1)
   *  dp(i) = dp(i-2) [if s[i-2:i] <= 26 && s[i-2] != 0]
   *        + dp(i-1) [if s[i-1] >= 0]
   * initial:
   *    dp(0) = 1 -> 1 way to decode null characters
   */
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1);

    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
      if(i > 1 && s[i-2] != '0') {
        dp[i] += dp[i-2] * (stoi(s.substr(i-2, 2)) <= 26);
      }
      dp[i] += dp[i-1] * (s[i-1] != '0');
    }
    return dp[n];
  }
};
