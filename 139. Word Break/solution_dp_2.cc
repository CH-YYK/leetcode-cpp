#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/* dp[i] -> whether s[0:i] (exclude s[i]) can meet the condition
 * * dp[i] = true if there is one k such that s[k:i] in wordDict and s[k] is
 true
 * * dp[i] = false if there is no k that make s[k:i] in wordDict or s[k] is true
 * -> dp[i] = dp[k] if s[k:i] in wordDict
 * -> dp[0] = true;
 O(N^2)
 * Optimize: check every k before i would be unnecessary
 *  * check word in wordDict would be better
 *  * i-1-k+1 = w.length() -> k = i - w.length()
 */
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    if (s.empty())
      return true;
    int n = s.size(), len;
    vector<int> dp(n+1, false);
    dp[0] = true;
    for(int i = 1; i <= n; ++i) {
      for(string& w : wordDict) {
        len = w.length();
        if(i-len >= 0 && s.substr(i-len, len) == w)
          dp[i] = dp[i-len] || dp[i];
      }
    }
    return dp[n];
  }
};
