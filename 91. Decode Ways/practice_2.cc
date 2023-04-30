#include <string>
#include <vector>
using namespace std;

/* f[i] = f[i+1] + f[i+2], f[i]: number of ways to decode s[i:]
 * dp[i] = dp[i-1] + dp[i-2], dp[i]: number of ways to decode s[:i+1]
 * dp[i] += dp[i-1] if s[i] > 0
 * dp[i] += dp[i-2] if s[i-1,i] <= 26
 */
class Solution {
public:
  int numDecodings(string s) {
    const int n = s.size();
    vector<int> dp(n, 0);
    if (s[0] == '0')
      return 0;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      int num = s[i - 1] - '0';
      num = 10 * num + s[i] - '0';
      if (num <= 26 && num >= 10)
        if (i > 1)
          dp[i] += dp[i - 2];
        else
          dp[i] = 1;
      num %= 10;
      if (num > 0)
        dp[i] += dp[i - 1];
    }
    return dp[n - 1];
  }
};
