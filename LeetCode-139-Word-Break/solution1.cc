#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  /* Non-empty string s and word dictionary. verify if s
   * can be segmented to words in wordDict
   * dp(i) -> whether s[0:i] can meet the condition
   *
   * for a word w in wordDict.
   *    dp[i] = dp[i-len(w)] && s[i-len(w): i] = w
   * dp(0) = True
   */
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size(), len;
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for(int i = 1; i <= n; ++i)
      for(string& w : wordDict) {
        len = w.size();
        if(i >= len && s.substr(i - len, len) == w)
          dp[i] = dp[i-len] || dp[i];
      }
    return dp[n];
  }
};
