#include <string>
#include <vector>
using namespace std;

/* f[i] = f[i+1] + f[i+2], f[i]: number of ways to decode s[i:]
 * dp[i] = dp[i-1] + dp[i-2], dp[i]: number of ways to decode s[:i+1]
 * dp[i] += dp[i-1] if s[i] > 0
 * dp[i] += dp[i-2] if s[i-1,i] <= 26
 *
 * Space deduction, O(N) to O(1)
 * a = dp[i-2], b = dp[i-1], a,b =a, a+b
 */
class Solution {
public:
  int numDecodings(string s) {
    const int n = s.size();
    if (s[0] == '0')
      return 0;
    int a = 1, b = 1, nb = 0, num = s[0] - '0';
    for (int i = 1; i < n; ++i) {
      num = 10 * num + (s[i] - '0');
      if (num <= 26 && num >= 10) nb += a;
      num %= 10;
      if (num > 0) nb += b;
      a = b, b = nb,  nb = 0;
    }
    return b;
  }
};
